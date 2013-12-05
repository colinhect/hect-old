#pragma once

namespace hect
{

///
/// Provides an interface for writing to a mesh without knowledge of the
/// vertex layout.
class MeshWriter
{
public:

    ///
    /// Constructs a mesh writer given a mesh to build on.
    ///
    /// \param mesh The mesh to build on.
    MeshWriter(Mesh& mesh);

    ///
    /// Adds a new vertex to the mesh.
    ///
    /// \returns The index of the added vertex.
    size_t addVertex();

    ///
    /// Sets attribute data of the most recently added vertex for a given
    /// semantic.
    ///
    /// \param semantic The semantic of the attribute to set the data for.
    /// \param value The value.
    void setAttributeData(VertexAttributeSemantic semantic, float value);

    ///
    /// Sets attribute data of the most recently added vertex for a given
    /// semantic.
    ///
    /// \param semantic The semantic of the attribute to set the data for.
    /// \param value The value.
    void setAttributeData(VertexAttributeSemantic semantic, const Vector2<float>& value);

    ///
    /// Sets attribute data of the most recently added vertex for a given
    /// semantic.
    ///
    /// \param semantic The semantic of the attribute to set the data for.
    /// \param value The value.
    void setAttributeData(VertexAttributeSemantic semantic, const Vector3<float>& value);

    ///
    /// Sets attribute data of the most recently added vertex for a given
    /// semantic.
    ///
    /// \param semantic The semantic of the attribute to set the data for.
    /// \param value The value.
    void setAttributeData(VertexAttributeSemantic semantic, const Vector4<float>& value);

    ///
    /// Adds an index to the mesh.
    void addIndex(uint64_t value);

private:
    void _setComponentValue(const VertexAttribute* attribute, unsigned index, float value);

    template <typename T>
    void _setAttributeData(const VertexAttribute& attribute, const T& value);

    Mesh* _mesh;
    size_t _vertexDataIndex;
};

}

#include "MeshWriter.inl"