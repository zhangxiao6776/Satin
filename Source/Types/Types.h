//
//  Types.h
//  Satin
//
//  Created by Reza Ali on 6/4/20.
//

#ifndef Vertex_h
#define Vertex_h

#include <stdbool.h>
#include <simd/simd.h>

typedef struct {
    simd_float4 position;
    simd_float3 normal;
    simd_float2 uv;
} Vertex;

typedef struct {
    uint32_t i0;
    uint32_t i1;
    uint32_t i2;
} TriangleIndices;

typedef struct {
    int vertexCount;
    Vertex *vertexData;
    int indexCount;
    TriangleIndices *indexData;
} GeometryData;

void freeGeometryData( GeometryData *data );

void copyGeometryVertexData( GeometryData *dest, GeometryData *src, int start, int end );
void copyGeometryIndexData( GeometryData *dest, GeometryData *src, int start, int end );
void copyGeometryData( GeometryData *dest, GeometryData *src );

void combineGeometryData( GeometryData *dest, GeometryData *src );
void combineAndOffsetGeometryData( GeometryData *dest, GeometryData *src, simd_float3 offset );
void combineAndScaleGeometryData( GeometryData *dest, GeometryData *src, simd_float3 scale );
void combineAndScaleAndOffsetGeometryData( GeometryData *dest, GeometryData *src, simd_float3 scale, simd_float3 offset );
void combineAndTransformGeometryData( GeometryData *dest, GeometryData *src, simd_float4x4 transform ); 

void computeNormalsOfGeometryData( GeometryData *data );
void reverseFacesOfGeometryData( GeometryData *data );

void transformGeometryData( GeometryData *data, simd_float4x4 transform ); 

#endif /* Types_h */
