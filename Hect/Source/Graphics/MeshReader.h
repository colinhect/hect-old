#pragma once

namespace hect
{

///
/// Provides an interface for reading from a mesh without knowledge of the
/// vertex layout.
class MeshReader
{
public:

    ///
    /// Constructs a mesh reader given a mesh to read from.
    ///
    /// \param mesh The mesh to read from.
    MeshReader(const Mesh& mesh);

    ///
    /// Moves to the next vertex in the mesh.
    ///
    /// \returns Whether there is a vertex left to read.
    bool nextVertex();

    ///
    /// Reads an the attribute with the given semantic as a float.
    ///
    /// \throws Error If the first vertex has not been moved to or attempting
    /// to read past the last vertex.
    float readAttributeFloat(VertexAttributeSemantic semantic) const;

    ///
    /// Reads an the attribute with the given semantic as a 2-dimensional
    /// vector.
    ///
    /// \throws Error If the first vertex has not been moved to or attempting
    /// to read past the last vertex.
    Vector2<float> readAttributeVector2(VertexAttributeSemantic semantic) const;

    ///
    /// Reads an the attribute with the given semantic as a 3-dimensional
    /// vector.
    ///
    /// \throws Error If the first vertex has not been moved to or attempting
    /// to read past the last vertex.
    Vector3<float> readAttributeVector3(VertexAttributeSemantic semantic) const;

    ///
    /// Reads an the attribute with the given semantic as a 4-dimensional
    /// vector.
    ///
    /// \throws Error If the first vertex has not been moved to or attempting
    /// to read past the last vertex.
    Vector4<float> readAttributeVector4(VertexAttributeSemantic semantic) const;

    ///
    /// Moves to the next index in the mesh.
    ///
    /// \returns Whether there is an index left to read.
    bool nextIndex();

    ///
    /// Reads the current index as an unsigned byte.
    ///
    /// \throws Error If the first index has not been moved to or attempting to
    /// read past the last index.
    uint8_t readIndexByte() const;

    ///
    /// Reads the current index as an unsigned short.
    ///
    /// \throws Error If the first index has not been moved to or attempting to
    /// read past the last index.
    uint16_t readIndexShort() const;

    ///
    /// Reads the current index as an unsigned int.
    ///
    /// \throws Error If the first index has not been moved to or attempting to
    /// read past the last index.
    uint32_t readIndexInt() const;

private:
    void _checkVertexBoundary() const;
    void _checkIndexBoundary() const;

    float _readComponentValue(const VertexAttribute* attribute, unsigned index) const;

    template <typename T>
    const T& _readAttributeData(const VertexAttribute& attribute) const;

    const Mesh* _mesh;

    size_t _vertexCount;
    size_t _vertexDataIndex;

    size_t _indexCount;
    size_t _indexDataIndex;
};

}

#include "MeshReader.inl"