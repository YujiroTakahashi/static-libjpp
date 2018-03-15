#include "core/features_api.h"

namespace jumanpp_generated {
class JumandicStatic: public jumanpp::core::features::StaticFeatureFactory {
jumanpp::core::features::NgramFeatureApply*ngram() const override;
jumanpp::core::features::PartialNgramFeatureApply*ngramPartial() const override;
jumanpp::core::features::GeneratedPatternFeatureApply*pattern() const override;
};
} //namespace jumanpp_generated
