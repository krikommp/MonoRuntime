using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;

namespace MonoCsharp
{
    public class Test<T>
    {
    }

    public class TestA
    {
    }

    public static class MainTest
    {
        static void Main()
        {
            System.Console.WriteLine("Hello World");
            List<int> list = new List<Int32>();
            list.Add(1);
            System.Console.WriteLine("Sample = " + Sample(1, new Test<int>()));
            System.Console.WriteLine("Sample_1 = " + Sample_1(1));
            System.Console.WriteLine("Sample_1 = " + Sample_1(1, 2));
            System.Console.WriteLine("Sample_1 = " + Sample_1(1, list));
            Dictionary<int, int> dic = new Dictionary<Int32, Int32>();
            dic.Add(1, 1);
            System.Console.WriteLine("Sample_1 = " + Sample_1(1, dic));
            HashSet<int> set = new HashSet<int>();
            set.Add(1);
            System.Console.WriteLine("Sample_1 = " + Sample_1(1, set));
            HashSet<TestA> set1 = new HashSet<TestA>();
            set1.Add(new TestA());
            System.Console.WriteLine("Sample_1 = " + Sample_1(1, set1));
            System.Console.WriteLine("End");
        }
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static string Sample (int a, Test<int> b);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static string Sample_1(int a);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static string Sample_1(int a, int b);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static string Sample_1(int a, List<int> b);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static string Sample_1(int a, Dictionary<int,int> b);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static string Sample_1(int a, HashSet<int> b);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static string Sample_1(int a, HashSet<TestA> b);
    }
}