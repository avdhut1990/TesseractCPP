#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main() {
    char *outText;

    char tessdataPrefix[]="TESSDATA_PREFIX=/Users/C2lBiz/Downloads/tessoutput"; 
    putenv(tessdataPrefix);

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("/Users/C2lBiz/Downloads/Avdhut/Google Vision/PAN v1/pan1.jpg");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}