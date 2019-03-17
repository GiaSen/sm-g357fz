 // Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "android/jni/jni_utils.h"
#include "base/logging.h"
#include "base/utf_string_conversions.h"
#include "jni.h"

namespace {
JavaVM* sVM = NULL;

JavaVM* getJavaVM() {
  return sVM;
}
}

namespace android {
namespace jni {

// All JNI code assumes this has previously been called with a valid VM
void SetJavaVM(JavaVM* vm)
{
  sVM = vm;
#ifdef SEC_PRODUCT_FEATURE_RIL_ENABLE_SMART_BONDING
//< RNTFIX:: JNI Support for streaming
    if(!sVM)
    {
      pthread_mutex_lock(&mut);
      if ((streamVM == NULL) && (false == created))
      {
        pthread_t ThreadId; 
        pthread_attr_t        attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        if(0 != pthread_create(&ThreadId,NULL,&createNewVM,0))
        {
          LOG(ERROR)<<"Call Back Thread Failed ";
        }/* End of if */
        while((streamVM == NULL) && (created == false)) 
        {
          //LOG(ERROR)<<"creating vm present status "<<created << " " <<streamVM;
          usleep(100000);
        }
      }
      pthread_mutex_unlock(&mut);
    }
//> RNTFIX
#endif
}

bool checkException(JNIEnv* env)
{
  if (env->ExceptionCheck() != 0)
  {
    LOG(ERROR) << "*** Uncaught exception returned from Java call!\n";
    env->ExceptionDescribe();
    return true;
  }
  return false;
}

string16 jstringToString16(JNIEnv* env, jstring jstr)
{
  if (!jstr || !env)
    return string16();

  const char* s = env->GetStringUTFChars(jstr, 0);
  if (!s)
    return string16();
  string16 str = UTF8ToUTF16(s);
  env->ReleaseStringUTFChars(jstr, s);
  checkException(env);
  return str;
}

std::string jstringToStdString(JNIEnv* env, jstring jstr)
{
  if (!jstr || !env)
    return std::string();

  const char* s = env->GetStringUTFChars(jstr, 0);
  if (!s)
    return std::string();
  std::string str(s);
  env->ReleaseStringUTFChars(jstr, s);
  checkException(env);
  return str;
}

JNIEnv* GetJNIEnv() {
  JNIEnv* env;
  getJavaVM()->AttachCurrentThread(&env, NULL);
  return env;
}

std::string JstringToStdString(JNIEnv* env, jstring jstr) {
  return jstringToStdString(env, jstr);
}

string16 JstringToString16(JNIEnv* env, jstring jstr)
{
    return jstringToString16(env, jstr);
}

bool CheckException(JNIEnv* env)
{
    return checkException(env);
}

jstring ConvertUTF8ToJavaString(JNIEnv* env, std::string str)
{
    return env->NewStringUTF(str.c_str());
}

void DetachFromVM()
{
    JavaVM* vm = getJavaVM();
    vm->DetachCurrentThread();
}

} // namespace jni
} // namespace android

