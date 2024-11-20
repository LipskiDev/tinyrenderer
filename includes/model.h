#ifndef MODEL_H
#define MODEL_H

#include "tr_math.h"
#include <vector>
#include <string>
#include "tgaimage.h"

class Model {
    std::vector<Vec3f> verts{};
    std::vector<Vec2f> tex_coords{};
    std::vector<Vec3f> normals{};

    std::vector<Vec3i> faces{};

public:
    Model(const std::string model_path);
    int nverts() const;
    int nfaces() const;
    std::vector<Vec3i> getFaces() const;
    void Draw(TGAImage &image, TGAColor color);

};

#endif // MODEL_H