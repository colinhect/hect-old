///////////////////////////////////////////////////////////////////////////////
// This source file is part of Hect.
//
// Copyright (c) 2014 Colin Hill
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
///////////////////////////////////////////////////////////////////////////////
SUITE(Vector4)
{
    template <typename T>
    void testDefaultConstructor()
    {
        Vector4<T> a;
        CHECK_CLOSE((T)0.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)0.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)0.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)0.0, a.w, (T)epsilon);
    }

    TEST(DefaultConstructor)
    {
        testDefaultConstructor<float>();
        testDefaultConstructor<double>();
    }

    template <typename T>
    void testScalarConstructor()
    {
        Vector4<T> a((T)1.0);
        CHECK_CLOSE((T)1.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)1.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)1.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)1.0, a.w, (T)epsilon);
    }

    TEST(ScalarConstructor)
    {
        testScalarConstructor<float>();
        testScalarConstructor<double>();
    }

    template <typename T>
    void testComponentConstructor()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        CHECK_CLOSE((T)1.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)2.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)3.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)4.0, a.w, (T)epsilon);
    }

    TEST(ComponentConstructor)
    {
        testComponentConstructor<float>();
        testComponentConstructor<double>();
    }

    template <typename T>
    void testCopyConstructor()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        Vector4<T> b(a);
        CHECK_CLOSE(a.x, b.x, (T)epsilon);
        CHECK_CLOSE(a.y, b.y, (T)epsilon);
        CHECK_CLOSE(a.z, b.z, (T)epsilon);
        CHECK_CLOSE(a.w, b.w, (T)epsilon);
    }

    TEST(CopyConstructor)
    {
        testCopyConstructor<float>();
        testCopyConstructor<double>();
    }

    template <typename T>
    void testLength()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        CHECK_CLOSE((T)std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w), a.length(), (T)epsilon);
    }

    TEST(Length)
    {
        testLength<float>();
        testLength<double>();
    }

    template <typename T>
    void testLengthSquared()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        CHECK_CLOSE(a.length(), (T)std::sqrt(a.lengthSquared()), (T)epsilon);
    }

    TEST(LengthSquared)
    {
        testLengthSquared<float>();
        testLengthSquared<double>();
    }

    template <typename T>
    void testNormalize()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        a.normalize();
        CHECK_CLOSE((T)1.0, a.length(), (T)epsilon);
    }

    TEST(Normalize)
    {
        testNormalize<float>();
        testNormalize<double>();
    }

    template <typename T>
    void testNormalized()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        CHECK_CLOSE((T)1.0, a.normalized().length(), (T)epsilon);
    }

    TEST(Normalized)
    {
        testNormalized<float>();
        testNormalized<double>();
    }

    template <typename T>
    void testAngleFrom()
    {
        CHECK_CLOSE((T)0.0, Vector4<T>::unitX().angleFrom(Vector4<T>::unitX()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)180.0, Vector4<T>::unitX().angleFrom(-Vector4<T>::unitX()).degrees(), (T)epsilon);

        CHECK_CLOSE((T)0.0, Vector4<T>::unitY().angleFrom(Vector4<T>::unitY()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)180.0, Vector4<T>::unitY().angleFrom(-Vector4<T>::unitY()).degrees(), (T)epsilon);

        CHECK_CLOSE((T)0.0, Vector4<T>::unitZ().angleFrom(Vector4<T>::unitZ()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)180.0, Vector4<T>::unitZ().angleFrom(-Vector4<T>::unitZ()).degrees(), (T)epsilon);

        CHECK_CLOSE((T)0.0, Vector4<T>::unitW().angleFrom(Vector4<T>::unitW()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)180.0, Vector4<T>::unitW().angleFrom(-Vector4<T>::unitW()).degrees(), (T)epsilon);

        CHECK_CLOSE((T)90.0, Vector4<T>::unitX().angleFrom(Vector4<T>::unitY()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitX().angleFrom(Vector4<T>::unitZ()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitX().angleFrom(Vector4<T>::unitW()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitY().angleFrom(Vector4<T>::unitX()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitY().angleFrom(Vector4<T>::unitZ()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitY().angleFrom(Vector4<T>::unitW()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitZ().angleFrom(Vector4<T>::unitX()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitZ().angleFrom(Vector4<T>::unitY()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitZ().angleFrom(Vector4<T>::unitW()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitW().angleFrom(Vector4<T>::unitX()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitW().angleFrom(Vector4<T>::unitY()).degrees(), (T)epsilon);
        CHECK_CLOSE((T)90.0, Vector4<T>::unitW().angleFrom(Vector4<T>::unitZ()).degrees(), (T)epsilon);
    }

    TEST(AngleFrom)
    {
        testAngleFrom<float>();
        testAngleFrom<double>();
    }

    template <typename T>
    void testAdd()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0) + Vector4<T>((T)2.0, (T)4.0, (T)6.0, (T)8.0);
        CHECK_CLOSE((T)3.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)6.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)9.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)12.0, a.w, (T)epsilon);
    }

    TEST(Add)
    {
        testAdd<float>();
        testAdd<double>();
    }

    template <typename T>
    void testAddEquals()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        a += Vector4<T>((T)2.0, (T)4.0, (T)6.0, (T)8.0);
        CHECK_CLOSE((T)3.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)6.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)9.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)12.0, a.w, (T)epsilon);
    }

    TEST(AddEquals)
    {
        testAddEquals<float>();
        testAddEquals<double>();
    }

    template <typename T>
    void testSubtract()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0) - Vector4<T>((T)2.0, (T)4.0, (T)6.0, (T)8.0);
        CHECK_CLOSE((T)-1.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)-2.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)-3.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)-4.0, a.w, (T)epsilon);
    }

    TEST(Subtract)
    {
        testSubtract<float>();
        testSubtract<double>();
    }

    template <typename T>
    void testSubtractEquals()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        a -= Vector4<T>((T)2.0, (T)4.0, (T)6.0, (T)8.0);
        CHECK_CLOSE((T)-1.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)-2.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)-3.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)-4.0, a.w, (T)epsilon);
    }

    TEST(SubtractEquals)
    {
        testSubtractEquals<float>();
        testSubtractEquals<double>();
    }

    template <typename T>
    void testMultiply()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0) * Vector4<T>((T)2.0, (T)4.0, (T)6.0, (T)8.0);
        CHECK_CLOSE((T)2.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)8.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)18.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)32.0, a.w, (T)epsilon);
    }

    TEST(Multiply)
    {
        testMultiply<float>();
        testMultiply<double>();
    }

    template <typename T>
    void testMultiplyEquals()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        a *= Vector4<T>((T)2.0, (T)4.0, (T)6.0, (T)8.0);
        CHECK_CLOSE((T)2.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)8.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)18.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)32.0, a.w, (T)epsilon);
    }

    TEST(MultiplyEquals)
    {
        testMultiplyEquals<float>();
        testMultiplyEquals<double>();
    }

    template <typename T>
    void testMultiplyScalar()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0) * (T)4.0;
        CHECK_CLOSE((T)4.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)8.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)12.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)16.0, a.w, (T)epsilon);
    }

    TEST(MultiplyScalar)
    {
        testMultiplyScalar<float>();
        testMultiplyScalar<double>();
    }

    template <typename T>
    void testMultiplyScalarEquals()
    {
        Vector4<T> a = Vector4<T>((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        a *= (T)4.0;
        CHECK_CLOSE((T)4.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)8.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)12.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)16.0, a.w, (T)epsilon);
    }

    TEST(MultiplyScalarEquals)
    {
        testMultiplyScalarEquals<float>();
        testMultiplyScalarEquals<double>();
    }

    template <typename T>
    void testDivide()
    {
        Vector4<T> a = Vector4<T>((T)6.0, (T)8.0, (T)12.0, (T)16.0) / Vector4<T>((T)2.0, (T)4.0, (T)4.0, (T)8.0);
        CHECK_CLOSE((T)3.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)2.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)3.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)2.0, a.w, (T)epsilon);
    }

    TEST(Divide)
    {
        testDivide<float>();
        testDivide<double>();
    }

    template <typename T>
    void testDivideEquals()
    {
        Vector4<T> a = Vector4<T>((T)6.0, (T)8.0, (T)12.0, (T)16.0);
        a /= Vector4<T>((T)2.0, (T)4.0, (T)4.0, (T)8.0);
        CHECK_CLOSE((T)3.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)2.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)3.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)2.0, a.w, (T)epsilon);
    }

    TEST(DivideEquals)
    {
        testDivideEquals<float>();
        testDivideEquals<double>();
    }

    template <typename T>
    void testDivideScalar()
    {
        Vector4<T> a = Vector4<T>((T)6.0, (T)8.0, (T)16.0, (T)24.0) / (T)2.0;
        CHECK_CLOSE((T)3.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)4.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)8.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)12.0, a.w, (T)epsilon);
    }

    TEST(DivideScalar)
    {
        testDivideScalar<float>();
        testDivideScalar<double>();
    }

    template <typename T>
    void testDivideScalarEquals()
    {
        Vector4<T> a = Vector4<T>((T)6.0, (T)8.0, (T)16.0, (T)24.0);
        a /= (T)2.0;
        CHECK_CLOSE((T)3.0, a.x, (T)epsilon);
        CHECK_CLOSE((T)4.0, a.y, (T)epsilon);
        CHECK_CLOSE((T)8.0, a.z, (T)epsilon);
        CHECK_CLOSE((T)12.0, a.w, (T)epsilon);
    }

    TEST(DivideScalarEquals)
    {
        testDivideScalarEquals<float>();
        testDivideScalarEquals<double>();
    }

    template <typename T, typename U>
    void testCast()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);
        Vector4<U> b = a;

        CHECK_CLOSE(a.x, (T)b.x, (T)epsilon);
        CHECK_CLOSE(a.y, (T)b.y, (T)epsilon);
        CHECK_CLOSE(a.z, (T)b.z, (T)epsilon);
        CHECK_CLOSE(a.w, (T)b.w, (T)epsilon);
    }

    TEST(Cast)
    {
        testCast<float, double>();
        testCast<double, float>();
    }

    template <typename T>
    void testIndex()
    {
        Vector4<T> a((T)1.0, (T)2.0, (T)3.0, (T)4.0);

        CHECK_CLOSE((T)1.0, a[0], (T)epsilon);
        CHECK_CLOSE((T)2.0, a[1], (T)epsilon);
        CHECK_CLOSE((T)3.0, a[2], (T)epsilon);
        CHECK_CLOSE((T)4.0, a[3], (T)epsilon);
    }

    TEST(Index)
    {
        testIndex<float>();
        testIndex<double>();
    }
}