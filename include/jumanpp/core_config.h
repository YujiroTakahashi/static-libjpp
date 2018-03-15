#pragma once
#ifndef __JUMANPP_CORE_CONFIG_H__
#define __JUMANPP_CORE_CONFIG_H__

#include <util/string_piece.h>

namespace jumanpp {
namespace core {

constexpr size_t JPP_MAX_DIC_FIELDS = 16;

#define JPP_PREFETCH_FEATURE_WEIGHTS 1

/* #undef JPP_ENABLE_DEV_TOOLS */

/* #undef JPP_USE_PROTOBUF */

/* #undef JPP_TRAIN_MID_NGRAMS */

#define JPP_TRAIN_VIOLATION_INVALID 1

static constexpr char JPP_DEFAULT_CONFIG_DIR[]{"/usr/local/libexec/jumanpp"};

}
}

#endif //__JUMANPP_CORE_CONFIG_H__
