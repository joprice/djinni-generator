// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from using_custom_datatypes.djinni

#include "custom_datatype.hpp"  // my header
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated {

CustomDatatype::CustomDatatype() = default;

CustomDatatype::~CustomDatatype() = default;

auto CustomDatatype::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<CustomDatatype>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.recordData)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto CustomDatatype::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 2);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<CustomDatatype>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_recordData))};
}

}  // namespace djinni_generated
