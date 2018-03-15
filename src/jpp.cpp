#include "jpp.h"

namespace croco {

/**
 * コンストラクタ
 *
 * @access public
 * @param  std::string modelpath
 */
Jpp::Jpp(std::string modelpath)
{
    _conf.modelFile = modelpath;
    _conf.rnnConfig.nceBias = 6;
    _conf.rnnConfig.unkConstantTerm = -5;
    _conf.rnnConfig.unkLengthPenalty = -3;
    _conf.rnnConfig.perceptronWeight = 1;
    _conf.rnnConfig.rnnWeight = 0.007;

    _env.loadModel(_conf.modelFile.value());
    _env.setBeamSize(_conf.beamSize);
    _env.setGlobalBeam(_conf.globalBeam, _conf.rightCheck, _conf.rightBeam);
    _env.setRnnConfig(_conf.rnnConfig);

    jumanpp_generated::JumandicStatic features;
    _env.initFeatures(&features);
    _env.makeAnalyzer(&_analyzer);
}

/**
 * デストラクタ
 *
 * @access public
 */
Jpp::~Jpp()
{
}

/**
 * 解析
 *
 * @access public
 * @param  jumanpp::StringPiece data
 * @return nlohmann::json
 */
nlohmann::json  Jpp::analyze(jumanpp::StringPiece data)
{
    _analyzer.analyze(data);

    jumanpp::jumandic::output::JumandicFields fields;
    jumanpp::core::analysis::AnalysisPath cursor;
    jumanpp::core::analysis::NodeWalker walker;

    auto& om = _analyzer.output();
    auto *ptr = _analyzer.impl()->lattice();

    fields.initialize(om);
    cursor.fillIn(ptr);

    nlohmann::json retval;
    int row = 0;

    while (cursor.nextBoundary()) {
        jumanpp::core::analysis::ConnectionPtr cptr;
        if (!cursor.nextNode(&cptr)) {
            return nlohmann::json(false);
        }

        if (!om.locate(cptr.latticeNodePtr(), &walker)) {
            return nlohmann::json(false);
        }

        if (!walker.next()) {
            return nlohmann::json(false);
        }

        retval[row]["surface"]  = fields.surface[walker].str();
        retval[row]["reading"]  = fields.reading[walker].str();
        retval[row]["baseform"] = fields.baseform[walker].str();
        retval[row]["pos"]      = fields.pos[walker].str();

        if (fields.subpos[walker].size() > 0) {
            retval[row]["subpos"] = fields.subpos[walker].str();
        }
        if (fields.conjType[walker].size() > 0) {
            retval[row]["subpos"] = fields.conjType[walker].str();
        }
        if (fields.conjForm[walker].size() > 0) {
            retval[row]["subpos"] = fields.conjForm[walker].str();
        }

        auto res = fields.features[walker];
        if (res.hasNext()) {
            while (res.next()) {
                if (res.hasValue()) {
                    retval[row]["subtext"] = true;
                }
            }
        }
        row++;
    }
    return retval;
}

}  // namespace croco
