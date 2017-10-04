#include "filesystem/blob.h"
#include "util.h"
#include "lib/vec/vec.h"

#pragma once

typedef struct {
  // material
  int drawStart;
  int drawCount;
} ModelPrimitive;

typedef struct ModelNode {
  float transform[16];
  int parent;
  vec_uint_t children;
  vec_uint_t primitives;
} ModelNode;

typedef struct {
  ModelNode* nodes;
  ModelPrimitive* primitives;
  float* vertices;
  uint32_t* indices;
  int nodeCount;
  int primitiveCount;
  int vertexSize;
  int vertexCount;
  int indexCount;
  int hasNormals;
  int hasUVs;
  float aabb[6];
} ModelData;

ModelData* lovrModelDataCreate(Blob* blob);
void lovrModelDataDestroy(ModelData* modelData);
