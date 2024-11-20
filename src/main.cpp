#include "../dependencies/tgaimage.h"
#include "drawing.h"
#include "model.h"
#include "config.h"
#include "tr_math.h"
#include <iostream>

const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor white = TGAColor(255, 255, 255, 255);

int main(int argc, char **argv) {
    TGAImage image(700, 700, TGAImage::RGB);
    Model face(ROOT_DIR"/assets/models/african_head.obj");
   
    face.Draw(image, white);

    image.flip_vertically();
    image.write_tga_file("../../output.tga");
    return 0;
}

