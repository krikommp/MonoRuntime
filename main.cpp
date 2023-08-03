#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/class.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>

MonoDomain* domain;

static MonoString* Sample(int a, MonoObject* b)
{
    char str[128] = { 0 };
    sprintf_s(str, "Hello, %d", a);
    return mono_string_new(mono_domain_get(), str);
}

static MonoString* Sample_1(int a)
{
    char str[128] = { 0 };
    sprintf_s(str, "Hello, %d", a);
    return mono_string_new(mono_domain_get(), str);
}

static MonoString* Sample_2(int a, int b)
{
    char str[128] = { 0 };
    sprintf_s(str, "Hello, %d, %d", a, b);
    return mono_string_new(mono_domain_get(), str);
}

static MonoString* Sample_3(int a, MonoObject* b)
{
    char str[128] = { 0 };
    sprintf_s(str, "Hello, %d", a);
    return mono_string_new(mono_domain_get(), str);
}

static MonoString* Sample_4(int a, MonoObject* b)
{
    char str[128] = { 0 };
    sprintf_s(str, "Hello, %d", a);
    return mono_string_new(mono_domain_get(), str);
}

static MonoString* Sample_5(int a, MonoObject* b)
{
    char str[128] = { 0 };
    sprintf_s(str, "Hello, %d", a);
    return mono_string_new(mono_domain_get(), str);
}

int main()
{
    // Program.cs所编译dll所在的位置
    const char* managed_binary_path = MONO_DLL;

    //获取应用域
    domain = mono_jit_init("Test");

    //加载程序集ManagedLibrary.dll
    MonoAssembly* assembly = mono_domain_assembly_open(domain, managed_binary_path);
    MonoImage* image = mono_assembly_get_image(assembly);

    // =====================================================准备调用
    //获取MonoClass,类似于反射
    MonoClass* main_class = mono_class_from_name(image, "MonoCsharp", "MainTest");

    //获取要调用的MonoMethodDesc,主要调用过程
    MonoMethodDesc* entry_point_method_desc = mono_method_desc_new("MonoCsharp.MainTest:Main()", true);
    MonoMethod* entry_point_method = mono_method_desc_search_in_class(entry_point_method_desc, main_class);
    mono_method_desc_free(entry_point_method_desc);
    mono_add_internal_call("MonoCsharp.MainTest::Sample(int,MonoCsharp.Test`1<int>)", (void*)Sample);
    mono_add_internal_call("MonoCsharp.MainTest::Sample_1(int)", (void*)Sample_1);
    mono_add_internal_call("MonoCsharp.MainTest::Sample_1(int,int)", (void*)Sample_2);
    mono_add_internal_call("MonoCsharp.MainTest::Sample_1(int,System.Collections.Generic.List`1<int>)", (void*)Sample_3);
    mono_add_internal_call("MonoCsharp.MainTest::Sample_1(int,System.Collections.Generic.Dictionary`2<int, int>)", (void*)Sample_4);
    mono_add_internal_call("MonoCsharp.MainTest::Sample_1(int,System.Collections.Generic.HashSet`1<int>)", (void*)Sample_5);

    //调用方法
    mono_runtime_invoke(entry_point_method, NULL, NULL, NULL);
    //释放应用域
    mono_jit_cleanup(domain);


    return 0;
}
