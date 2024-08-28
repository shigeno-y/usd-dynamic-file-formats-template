// SPDX-License-Identifier: MIT

#ifndef SHIGENOY_USDDYNAMICFILEFORMATS_PLUGIN_BODY_HPP_INCLUDED
#define SHIGENOY_USDDYNAMICFILEFORMATS_PLUGIN_BODY_HPP_INCLUDED

#include <iosfwd>
#include <string>

#include "pxr/base/tf/staticTokens.h"
#include "pxr/pxr.h"
#include "pxr/usd/pcp/dynamicFileFormatInterface.h"
#include "pxr/usd/sdf/fileFormat.h"

PXR_NAMESPACE_OPEN_SCOPE

#define USDDYNAMICFILEFORMATSTEMPLATETOKENS \
    ((Id, "o_o"))((Version, "1.0"))((Target, "usd"))

TF_DECLARE_PUBLIC_TOKENS(UsdDynamicFileFormatsTokens,
                         USDDYNAMICFILEFORMATSTEMPLATETOKENS);

TF_DECLARE_WEAK_AND_REF_PTRS(UsdDynamicFileFormats);

class UsdDynamicFileFormats : public SdfFileFormat,
                              public PcpDynamicFileFormatInterface {
   public:
    // SdfFileFormat overrides.
    virtual bool CanRead(const std::string& file) const override;
    virtual bool Read(SdfLayer* layer, const std::string& resolvedPath,
                      bool metadataOnly) const override;
    /*
    virtual bool ReadFromString(SdfLayer* layer, const std::string& str) const
    override;
    // */

    /*
    virtual bool WriteToString(const SdfLayer& layer,
                               std::string* str,
                               const std::string& comment = std::string()) const
    override;
    // */
    /*virtual bool
    WriteToStream(const SdfSpecHandle& spec, std::ostream& out, size_t indent)
    const override;
    */

    void ComposeFieldsForFileFormatArguments(
        const std::string& assetPath,
        const pxr::PcpDynamicFileFormatContext& context,
        pxr::SdfFileFormat::FileFormatArguments* args,
        pxr::VtValue* contextDependencyData) const override;

    bool CanFieldChangeAffectFileFormatArguments(
        const pxr::TfToken& field, const pxr::VtValue& oldValue,
        const pxr::VtValue& newValue,
        const pxr::VtValue& contextDependencyData) const override;

    /*
    bool CanAttributeDefaultValueChangeAffectFileFormatArguments(
        const pxr::TfToken& field,
        const pxr::VtValue& oldValue,
        const pxr::VtValue& newValue,
        const pxr::VtValue& contextDependencyData) const override;
    // */

   protected:
    SDF_FILE_FORMAT_FACTORY_ACCESS;

    virtual ~UsdDynamicFileFormats();
    UsdDynamicFileFormats();
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_EXTRAS_USD_EXAMPLES_USD_OBJ_FILE_FORMAT_H
