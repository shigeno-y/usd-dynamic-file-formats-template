// SPDX-License-Identifier: MIT

#include "body.hpp"

#include "logger_loader.hpp"
#include "pxr/usd/pcp/dynamicFileFormatContext.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(UsdDynamicFileFormatsTokens, USDPMM_FILE_FORMAT_TOKENS);

TF_REGISTRY_FUNCTION(TfType) {
    SDF_DEFINE_FILE_FORMAT(UsdDynamicFileFormats, SdfFileFormat);
}

UsdDynamicFileFormats::UsdDynamicFileFormats()
    : SdfFileFormat(UsdDynamicFileFormatsTokens->Id,
                    UsdDynamicFileFormatsTokens->Version,
                    UsdDynamicFileFormatsTokens->Target,
                    UsdDynamicFileFormatsTokens->Id) {}

UsdDynamicFileFormats::~UsdDynamicFileFormats() {}

bool UsdDynamicFileFormats::CanRead(const std::string& filePath) const {
    // Could check to see if it looks like valid obj data...
    return true;
}

bool UsdDynamicFileFormats::Read(SdfLayer* layer,
                                 const std::string& resolvedPath,
                                 bool metadataOnly) const {
    auto logger = shigenoy::usd_dynamic_file_formats::common::load_logger();
    logger->info("UsdDynamicFileFormats::Read, do your work here!");
    return true;
}

void UsdDynamicFileFormats::ComposeFieldsForFileFormatArguments(
    const std::string& assetPath,
    const pxr::PcpDynamicFileFormatContext& context,
    pxr::SdfFileFormat::FileFormatArguments* args,
    pxr::VtValue* contextDependencyData) const {
    auto logger = shigenoy::usd_dynamic_file_formats::common::load_logger();
    // for someParam
    {
        const pxr::TfToken someParam{"someParam"};
        pxr::VtValue val;
        if (context.ComposeValue(someParam, &val) &&
            val.IsHolding<unsigned int>()) {
            const auto value = val.Get<unsigned int>();
            args->operator[](someParam) = pxr::TfStringify(value);
            logger->info("FileFormatArguments <{}> is <>",
                         someParam.GetString(), value);
        }
    }
}

bool UsdDynamicFileFormats::CanFieldChangeAffectFileFormatArguments(
    const pxr::TfToken& field, const pxr::VtValue& oldValue,
    const pxr::VtValue& newValue,
    const pxr::VtValue& contextDependencyData) const {
    // each metadata or SDF args affects loaded (or `baked') data
    return true;
}

PXR_NAMESPACE_CLOSE_SCOPE
