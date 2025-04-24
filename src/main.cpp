#include <opencv2/opencv.hpp>
#include <iostream>

// int main() {
//     cv::Mat image = cv::imread("/Users/chenhaoping/Downloads/track_53_1745141758.795.jpg");
//     if (image.empty()) {
//         std::cerr << "Failed to load image." << std::endl;
//         return -1;
//     }

//     cv::imshow("Display Image", image);
//     cv::waitKey(0);
//     return 0;
// }


int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open camera." << std::endl;
        return -1;
    }

    // Load face detection model
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("data/haarcascade_frontalface_default.xml")) {
        std::cerr << "Error loading face cascade." << std::endl;
        return -1;
    }

    cv::Mat frame, mirrored, gray;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cv::flip(frame, mirrored, 1); // Mirror the image
        cv::cvtColor(mirrored, gray, cv::COLOR_BGR2GRAY); // Convert to grayscale
        cv::equalizeHist(gray, gray); // Enhance contrast

        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(gray, faces);

        for (const auto& face : faces) {
            cv::rectangle(mirrored, face, cv::Scalar(0, 255, 0), 2);
        }

        cv::imshow("Mirrored Face Detection", mirrored);
        if (cv::waitKey(10) == 27) break; // ESC to exit
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}