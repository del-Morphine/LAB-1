#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Image {
public:
    string fileName;
    int width;
    int height;

    Image(string name, int w, int h) : fileName(name), width(w), height(h) {}
};

class ImageSaveRemover {
public:
    static void Save(const Image& image) {
        cout << "Saving image: " << image.fileName << endl;
    }

    static int DeleteDuplicates() {
        cout << "Deleting duplicate images " << endl;
        return 14; 
    }
};

class AccountImageManager {
public:
    static void SetAsAccountPicture(const Image& image) {
        cout << "Setting " << image.fileName << " as account avatar." << endl;
    }
};

class ImageEditor {
public:
    static void Resize(Image& image, int height, int width) {
        image.width = width;
        image.height = height;
        cout << "Resized image to " << image.width << "x" << image.height << endl;
    }

    static void InvertColors(const Image& image) {
        cout << "Inverting colors " << image.fileName << endl;
    }
};

class ImageDownloader {
public:
    static vector<unsigned char> Download(const string& imageUrl) {
        cout << "Downloading image " << imageUrl << endl;
        return {}; 
    }
};

int main() {
    Image image("example_image.jpg", 1080, 768);

    ImageSaveRemover::Save(image);
    ImageEditor::Resize(image, 800, 600);
    int deleted = ImageSaveRemover::DeleteDuplicates();
    cout << "Deleted " << deleted << " duplicate images." << endl;
    AccountImageManager::SetAsAccountPicture(image);

    return 0;
}
