#pragma once

namespace hect
{

///
/// A uniform value type.
enum class UniformType
{
    ///
    /// An integer.
    Int,

    ///
    /// A floating point number.
    Float,

    ///
    /// A 2-dimensional vector.
    Vector2,

    ///
    /// A 3-dimensional vector.
    Vector3,

    ///
    /// A 4-dimensional vector.
    Vector4,

    ///
    /// A 4 by 4 matrix.
    Matrix4,

    ///
    /// A texture (the index of the texture).
    Texture
};

///
/// A value for a uniform.
///
/// \remarks A uniform's type cannot change.
class UniformValue
{
public:

    ///
    /// Constructs a default uniform value.
    UniformValue();

    ///
    /// Constructs a uniform value given its type.
    ///
    /// \param type The type.
    UniformValue(UniformType type);

    ///
    /// Constructs an integer based uniform value given its the integer value
    /// and its type.
    ///
    /// \param value The integer value.
    /// \param type The type.
    UniformValue(int value, UniformType type);

    ///
    /// Constructs a float uniform value.
    ///
    /// \param value The value.
    UniformValue(float value);

    ///
    /// Constructs a 2-dimensional vector uniform value.
    ///
    /// \param value The value.
    UniformValue(const Vector2<float>& value);

    ///
    /// Constructs a 3-dimensional vector uniform value.
    ///
    /// \param value The value.
    UniformValue(const Vector3<float>& value);

    ///
    /// Constructs a 4-dimensional vector uniform value.
    ///
    /// \param value The value.
    UniformValue(const Vector4<float>& value);

    ///
    /// Constructs a 4 by 4 matrix uniform value.
    ///
    /// \param value The value.
    UniformValue(const hect::Matrix4<float>& value);

    ///
    /// Returns the type.
    UniformType type() const;

    ///
    /// Returns the raw data.
    const void* data() const;

    ///
    /// Sets the value of the uniform value as an integer.
    ///
    /// \param value The value.
    ///
    /// \throws Error If the uniform value is not an integer or texture.
    void setValue(int value);

    ///
    /// Sets the value of the uniform value as a float.
    ///
    /// \param value The value.
    ///
    /// \throws Error If the uniform value is not a float.
    void setValue(float value);

    ///
    /// Sets the value of the uniform value as a 2-dimensional vector.
    ///
    /// \param value The value.
    ///
    /// \throws Error If the uniform value is not a 2-dimensional vector.
    void setValue(const Vector2<float>& value);

    ///
    /// Sets the value of the uniform value as a 3-dimensional vector.
    ///
    /// \param value The value.
    ///
    /// \throws Error If the uniform value is not a 3-dimensional vector.
    void setValue(const Vector3<float>& value);

    ///
    /// Sets the value of the uniform value as a 4-dimensional vector.
    ///
    /// \param value The value.
    ///
    /// \throws Error If the uniform value is not a 4-dimensional vector.
    void setValue(const Vector4<float>& value);

    ///
    /// Sets the value of the uniform value as a 4 by 4 matrix.
    ///
    /// \param value The value.
    ///
    /// \throws Error If the uniform value is not a 4 by 4 matrix.
    void setValue(const Matrix4<float>& value);

private:
    UniformType _type;

    union
    {
        int intValue;
        float floatValues[16];
    } _value;
};

}