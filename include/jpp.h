#ifndef __CROCO_JPP_H__
#define __CROCO_JPP_H__

#include "jpp_jumandic_cg.h"
#include "core/analysis/analyzer_impl.h"
#include "jumandic/shared/juman_format.h"
#include "jumandic/shared/jumandic_env.h"
#include "util/logging.hpp"

#include "json.hpp"

namespace croco {

class Jpp {
private:
    jumanpp::jumandic::JumanppConf _conf;
    jumanpp::core::JumanppEnv _env;
    jumanpp::core::analysis::Analyzer _analyzer;

public:
    Jpp(std::string modelpath);
    ~Jpp();
    nlohmann::json analyze(jumanpp::StringPiece data);
}; // class Jpp

} // namespace croco

#endif // #define __CROCO_JPP_H__
