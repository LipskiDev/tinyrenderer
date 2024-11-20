#include <iostream>
#include <sstream>
#include <fstream>
#include "model.h"
#include "drawing.h"

Model::Model(const std::string model_path) {
    std::ifstream in;
    in.open(model_path, std::ifstream::in);

    if(in.fail()) {
        std::cerr << "Failed to load model from " << model_path << std::endl;
        return;
    }

    std::string line;
    while(!in.eof()) {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        size_t spacePos = line.find(" ");
        std::string mode = line.substr(0, spacePos);
        if(mode == "v") {
            iss >> trash;
            Vec3f vert;
            for(int i = 0; i < 3; i++) {
                iss >> vert[i];
            }
            verts.push_back(vert);
        } else if(mode == "f") {
            int f, n, t;
            iss >> trash;
            std::vector<int> face_verts{};

            for(int i = 0; i < 3; i++) {
                iss >> f >> trash >> t >> trash >> n;
                face_verts.push_back(f - 1);
            }
            Vec3i face{face_verts[0], face_verts[1], face_verts[2]};
            faces.push_back(face);
        } else if(mode == "vn") {
            iss >> trash >> trash;
            Vec3f normal;
            for(int i = 0; i < 3; i++) {
                iss >> normal[i];
            }
            normals.push_back(normal);
        }
    }
}

int Model::nverts() const {
    return verts.size();
}

int Model::nfaces() const {
    return faces.size();
}

std::vector<Vec3i> Model::getFaces() const {
    return faces;
}

void Model::Draw(TGAImage &image, TGAColor color) {
    int image_width = image.get_width();
    int image_height = image.get_height();
    std::vector<Vec3i> face_vec = getFaces();
    for(int i = 0; i < face_vec.size(); i++) {
        Vec3i face = face_vec.at(i);
        for(int j = 0; j < 3; j++) {
            Vec3f v0 = verts[face[j]];
            Vec3f v1 = verts[face[((j + 1) % 3)]];
            int x0 = (v0[0] + 1.0) * image_width / 2.0;
            int y0 = (v0[1] + 1.0) * image_height / 2.0;
            int x1 = (v1[0] + 1.0) * image_width / 2.0;
            int y1 = (v1[1] + 1.0) * image_height / 2.0;
            line(x0, y0, x1, y1, image, color);
        }
    }
}

// italienische kräuter
// paprika scharf
// lorbeerbläter
// oregano
// basilikum
// paprika süss