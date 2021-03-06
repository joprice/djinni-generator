// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from my_record.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "my_record.hpp"

namespace djinni_generated {

class MyRecord final {
public:
    using CppType = ::MyRecord;
    using JniType = jobject;

    using Boxed = MyRecord;

    ~MyRecord();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    MyRecord();
    friend ::djinni::JniClass<MyRecord>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("djinni/it/MyRecord") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(ILjava/lang/String;Ljava/util/HashSet;Ljava/util/HashMap;)V") };
    const jfieldID field_id { ::djinni::jniGetFieldID(clazz.get(), "id", "I") };
    const jfieldID field_info { ::djinni::jniGetFieldID(clazz.get(), "info", "Ljava/lang/String;") };
    const jfieldID field_store { ::djinni::jniGetFieldID(clazz.get(), "store", "Ljava/util/HashSet;") };
    const jfieldID field_hash { ::djinni::jniGetFieldID(clazz.get(), "hash", "Ljava/util/HashMap;") };
};

}  // namespace djinni_generated
