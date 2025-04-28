#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open camera." << std::endl;
        return -1;
    }

    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("data/haarcascade_frontalface_default.xml")) {
        std::cerr << "Error loading face cascade." << std::endl;
        return -1;
    }

    cv::Mat frame, mirrored, gray;
    double fps = 0.0;
    int64 last_time = cv::getTickCount();

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // Mirror and grayscale
        cv::flip(frame, mirrored, 1);
        cv::cvtColor(mirrored, gray, cv::COLOR_BGR2GRAY);
        cv::equalizeHist(gray, gray);

        // Face detection
        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(gray, faces);

        for (const auto& face : faces) {
            cv::rectangle(mirrored, face, cv::Scalar(0, 255, 0), 2);
        }

        // FPS calculation
        int64 current_time = cv::getTickCount();
        double time_diff = (current_time - last_time) / cv::getTickFrequency();
        fps = 1.0 / time_diff;
        last_time = current_time;

        // Overlay FPS
        std::string fps_text = "FPS: " + std::to_string(static_cast<int>(fps));
        cv::putText(mirrored, fps_text, cv::Point(10, 30),
                    cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 0, 0), 2);

        cv::imshow("Face Detection with FPS", mirrored);
        if (cv::waitKey(1) == 27) break; // ESC
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
