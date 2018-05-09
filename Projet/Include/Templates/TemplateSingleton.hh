//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_TEMPLATESINGLETON_HH
#define INC_2DGAMEFRAMEWORK_TEMPLATESINGLETON_HH

template<class T>
class TemplateSingleton {
public:
  static T *get_instance() {
    if (!instance_)
      instance_ = new T();

    return instance_;
  }

  static void destroy_instance() {
    delete instance_;
    instance_ = nullptr;
  }

private:
  static T *instance_;
};

template<class T> T *TemplateSingleton<T>::instance_ = nullptr;

//===============================

// Implementation Example :
/*
class SingletonTest : public Singleton<SingletonTest>
{
public:
  SingletonTest(std::string s): s_(s) {}

private:
  std::string s_;
};
*/
#endif //INC_2DGAMEFRAMEWORK_TEMPLATESINGLETON_HH
