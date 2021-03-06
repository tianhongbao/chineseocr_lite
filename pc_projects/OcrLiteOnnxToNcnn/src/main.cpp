#include "OcrLite.h"

int main(int argc, char **argv) {
    if (argc <= 1) {
        fprintf(stderr,
                "Usage: %s img/path models/dir imgResize(option) boxScoreThresh(option) boxThresh(option) minArea(option) angleScaleWidth(option) angleScaleHeight(option) textScaleWidth(option) textScaleHeight(option)\n",
                argv[0]);
        fprintf(stderr, "Example: %s ../test/1.jpg ../models\n", argv[0]);
        fprintf(stderr, "Example: %s ../test/1.jpg ../models 0 0.6 0.3 3 1.3 1.3 1.6 1.6\n", argv[0]);
    } else {
        std::string argImgPath, imgPath, imgName, modelsDir;
        argImgPath = "../test/1.jpg";
        modelsDir = "../models";
        int imgResize = 0;
        float boxScoreThresh = 0.6f;
        float boxThresh = 0.3f;
        float minArea = 3.f;
        float angleScaleWidth = 1.3f;
        float angleScaleHeight = 1.3f;
        float textScaleWidth = 1.6f;
        float textScaleHeight = 1.6f;

        for (int i = 1; i < argc; ++i) {
            printf("argv[%d]=%s, ", i, argv[i]);
            switch (i) {
                case 1:
                    argImgPath = std::string(argv[i]);
                    imgPath = argImgPath.substr(0, argImgPath.find_last_of('/') + 1);
                    imgName = argImgPath.substr(argImgPath.find_last_of('/') + 1);
                    printf("imgPath=%s, imgName=%s\n", imgPath.c_str(), imgName.c_str());
                    break;
                case 2:
                    modelsDir = argv[i];
                    printf("modelsPath=%s\n", modelsDir.c_str());
                    break;
                case 3:
                    imgResize = (int) strtol(argv[i], NULL, 10);
                    printf("imgResize=%d\n", imgResize);
                    break;
                case 4:
                    boxScoreThresh = strtof(argv[i], NULL);
                    printf("boxScoreThresh=%f\n", boxScoreThresh);
                    break;
                case 5:
                    boxThresh = strtof(argv[i], NULL);
                    printf("boxThresh=%f\n", boxThresh);
                    break;
                case 6:
                    minArea = strtof(argv[i], NULL);
                    printf("minArea=%f\n", minArea);
                    break;
                case 7:
                    angleScaleWidth = strtof(argv[i], NULL);
                    printf("angleScaleWidth=%f\n", angleScaleWidth);
                    break;
                case 8:
                    angleScaleHeight = strtof(argv[i], NULL);
                    printf("angleScaleHeight=%f\n", angleScaleHeight);
                    break;
                case 9:
                    textScaleWidth = strtof(argv[i], NULL);
                    printf("textScaleWidth=%f\n", textScaleWidth);
                    break;
                case 10:
                    textScaleHeight = strtof(argv[i], NULL);
                    printf("textScaleHeight=%f\n", textScaleHeight);
                    break;
            }
        }

        OcrLite ocrLite;
        ocrLite.initLogger(imgPath.c_str(), imgName.c_str(), true, true, true, true, true);
        bool ret = ocrLite.initModels(modelsDir.c_str());
        if (!ret) return -1;

        OcrResult result = ocrLite.detect(imgPath.c_str(), imgName.c_str(), imgResize, boxScoreThresh, boxThresh,
                                          minArea, angleScaleWidth,
                                          angleScaleHeight, textScaleWidth, textScaleHeight);
        printf("%s\n", result.strRes.c_str());
    }

    return 0;
}
