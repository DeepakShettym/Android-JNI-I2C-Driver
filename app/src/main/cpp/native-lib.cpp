#include <jni.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <android/log.h>

#include "leddriver.h"

extern "C" JNIEXPORT void JNICALL Java_com_example_MyClass_callJavaFunction(JNIEnv* env, jobject obj);

static int hello(JNIEnv *env, jobject obj){
    __android_log_print(ANDROID_LOG_INFO, "MyTag", "The value is hello3");
    Java_com_example_MyClass_callJavaFunction(env, obj);
    return 0;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_MainActivity_stringFromJNI(JNIEnv* env,jobject /* this */) {
    std::string hello = "Hello --from C++";

    __android_log_print(ANDROID_LOG_INFO, "MyTag", "The value is hello1");
    __android_log_print(ANDROID_LOG_INFO, "MyTag", "hey made changes by deepakm");

    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_MyClass_callJavaFunction(JNIEnv* env, jobject obj) {
    // Find the Java class
    jclass clazz = env->FindClass("com/example/MyClass");

    // Find the method ID of the Java function
    jmethodID methodID = env->GetStaticMethodID(clazz, "javaFunction", "()V");

    __android_log_print(ANDROID_LOG_INFO, "MyTag", "The value is hello4");

    // Call the Java function
    env->CallStaticVoidMethod(clazz, methodID);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_MainActivity_callJavaFunction(JNIEnv *env, jobject thiz) {
    hello(reinterpret_cast<JNIEnv *>(env), thiz);
    __android_log_print(ANDROID_LOG_INFO, "MyTag", "The value is hello2");

}



extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1Init(JNIEnv *env, jobject thiz) {
    jint result = ledDriver_Init();
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_Init: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1Output(JNIEnv *env, jobject thiz, jbyte enable) {
    unsigned char uchar_value = static_cast<unsigned char>(enable & 0xFF);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_Output set value: %d", uchar_value);
    jint result = ledDriver_Output(uchar_value);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_Output: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1GetOutputStatus(JNIEnv *env, jobject thiz) {
    jint result = ledDriver_GetOutputStatus();
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_GetOutputStatus: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1SetIntensity(JNIEnv *env, jobject thiz, jbyte intensity) {
    unsigned char uchar_value = static_cast<unsigned char>(intensity & 0xFF);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_SetIntensity set value: %d", uchar_value);
    jint result = ledDriver_SetIntensity(uchar_value);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_SetIntensity: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1GetIntensity(JNIEnv *env, jobject thiz) {
    jint result = ledDriver_GetIntensity();
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_GetIntensity: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1DeInit(JNIEnv *env, jobject thiz) {
    jint result = ledDriver_DeInit();
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_DeInit: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1SetChannelTonTime(JNIEnv *env, jobject thiz,
                                                           jbyte channel_no, jint t_on_time) {
    unsigned char uchar_value = static_cast<unsigned char>(channel_no & 0xFF);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_SetChannelTonTime set Intensity: %d:%d", uchar_value,t_on_time);
    jint result = ledDriver_SetChannelTonTime(uchar_value,t_on_time);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_SetChannelTonTime: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1GetChannelTonTime(JNIEnv *env, jobject thiz,
                                                           jbyte channel_no) {
    unsigned char uchar_value = static_cast<unsigned char>(channel_no & 0xFF);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_GetChannelTonTime set value: %d", uchar_value);
    jint result = ledDriver_GetChannelTonTime(uchar_value);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_GetChannelTonTime: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1EnableChannel(JNIEnv *env, jobject thiz, jbyte channel_no,
                                                       jbyte channel_enable) {
    unsigned char uchar_value = static_cast<unsigned char>(channel_no & 0xFF);
    unsigned char channel_status = static_cast<unsigned char>(channel_enable & 0xFF);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_EnableChannel set value: channel_no: %d, channel_status: %d", uchar_value,channel_status);
    jint result = ledDriver_EnableChannel(uchar_value,channel_status);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_EnableChannel: %d", result);
    return result;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_ledDriver_1GetChannelStatus(JNIEnv *env, jobject thiz,
                                                          jbyte channel_no) {
    unsigned char uchar_value = static_cast<unsigned char>(channel_no & 0xFF);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_GetChannelStatus set value: %d", uchar_value);
    jint result = ledDriver_GetChannelStatus(uchar_value);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_GetChannelStatus: %d", result);
    return result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_getLedRegisterStatusValue(JNIEnv *env, jobject thiz,
                                                        jbyte register_address) {
    unsigned char uchar_value = static_cast<unsigned char>(register_address & 0xff);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "getLedRegisterStatusValue  uchar_value: %x", uchar_value);
    jint result = ledDriver_GetRegVal(uchar_value);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "getLedRegisterStatusValue: %d", result);
    return result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_MainActivity_setLedRegisterValue(JNIEnv *env, jobject thiz, jbyte register_address,
                                                  jbyte register_value) {
    unsigned char register_address_ = static_cast<unsigned char>(register_address & 0xFF);
    unsigned char register_value_ = static_cast<unsigned char>(register_value & 0xFF);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_SetRegVal set value: register_address: %d, register_value: %d", register_address,register_value);
    jint result = ledDriver_SetRegVal(register_address_,register_value_);
    __android_log_print(ANDROID_LOG_DEBUG, "LED_CONTROL", "ledDriver_SetRegVal: %d", result);
    return result;
}


/*
 * #include <iostream>
#include <vector>
#include <functional>
using namespace std;

vector<int> v;

vector<std::function<void()>> v_func;


void insertionInArrayOfVectors(int x){
    v.push_back(x);
}

void printElementsOfVector(){
    for (auto it = v.begin(); it != v.end(); ++it){
        cout << *it << ' ';
    }
}

void print_num( int x){
    cout << x << endl;
}


template <typename Temp>
Temp myMax(Temp x, Temp y)
{
    return (x>y)? x:y;
}

int multiply(int a, int b) {
    return a * b;
}

int add(int a, int b) {
    return a + b;
}

struct FuncInfo {
    std::function<int(int, int)> func;
    std::string name;
    int arg1;
    int arg2;
};


int main(){
    // insertionInArrayOfVectors(5);
    // insertionInArrayOfVectors(7);
    // insertionInArrayOfVectors(9);

    // printElementsOfVector();

    // for(auto i: v){
    //     cout << i << ' ';
    // }

    // cout << myMax<int>(3,7) << endl;
    std::function<void()> f_print_num = std::bind(print_num, 313378);
    f_print_num();

    std::vector<std::pair<std::function<int(int, int)>, std::pair<int, int>>> vec;

    vec.emplace_back(multiply, std::make_pair(5, 3));
    vec.emplace_back(add, std::make_pair(5, 3));

    for (const auto& i : vec) {
        std::cout << "Result: " << i.first(i.second.first, i.second.second) << std::endl;
    }


    std::vector<FuncInfo> vec1;

    vec1.push_back({multiply, "multiply", 5, 3});
    vec1.push_back({add, "add", 5, 3});

    for (const auto& i : vec1) {
        std::cout << "Executing: " << i.name << std::endl;
        std::cout << "Result: " << i.func(i.arg1, i.arg2) << std::endl;
    }

    // for(auto i:v_func){
    //     cout << i << ' ';
    // }

    return 0;
}

*/

//-------------------------------------
/*
    Using std::function: Since the function signatures are different,
    use std::function to store function pointers with various signatures.
    Storing Arguments: You can store the arguments for each function in a
    std::tuple to handle different numbers and types of arguments.

Sample Code

cpp

#include <iostream>
#include <vector>
#include <functional>
#include <tuple>

// Define example functions with different signatures
void func1(int a) {
    std::cout << "func1: " << a << std::endl;
}

void func2(double b, std::string c) {
    std::cout << "func2: " << b << ", " << c << std::endl;
}

void func3(int x, double y, char z) {
    std::cout << "func3: " << x << ", " << y << ", " << z << std::endl;
}

// Type alias to simplify the storage of functions
using FuncType = std::function<void(std::tuple<>)>;

// Utility to call a function with a tuple of arguments
template<typename F, typename Tuple, std::size_t... I>
void invoke_with_tuple(F f, Tuple&& t, std::index_sequence<I...>) {
    f(std::get<I>(std::forward<Tuple>(t))...);
}

template<typename F, typename Tuple>
void invoke(F f, Tuple&& t) {
    invoke_with_tuple(f, std::forward<Tuple>(t),
                      std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
}

// Store the function and corresponding argument tuple
struct FunctionWrapper {
    FuncType function;
    std::tuple<> args;
};

// Specialize the struct to allow different function arguments
template<typename F, typename... Args>
FunctionWrapper make_function_wrapper(F f, Args&&... args) {
    auto bound_func = [f](std::tuple<Args...> t) {
        invoke(f, std::move(t));
    };
    return {FuncType(bound_func), std::make_tuple(std::forward<Args>(args)...)};
}

int main() {
    // Create a vector of function wrappers
    std::vector<FunctionWrapper> functions;

    // Store different functions with their arguments
    functions.push_back(make_function_wrapper(func1, 42));
    functions.push_back(make_function_wrapper(func2, 3.14, std::string("Hello")));
    functions.push_back(make_function_wrapper(func3, 10, 20.5, 'a'));

    // Call the functions with their stored arguments
    for (auto& func : functions) {
        func.function(func.args);
    }

    return 0;
}

Explanation:

    Function Signatures: The example includes three functions func1, func2, and func3, each with different
    argument types and counts.

    FunctionWrapper: A FunctionWrapper struct stores the function and its arguments using std::function and std::tuple.
    Invoker: The invoke_with_tuple and invoke helper functions unpack the tuple arguments to call the stored function
    with the correct arguments.

    make_function_wrapper: This function helps create a FunctionWrapper by binding a function and its arguments,
    which are then stored in the vector.
    Executing Functions: The stored functions are executed in the for loop by calling the function with its respective
    arguments.

This approach allows you to store and manage a collection of functions with varying signatures and their arguments
 in a std::vector.*/

