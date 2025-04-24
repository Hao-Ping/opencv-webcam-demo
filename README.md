🎥 OpenCV Webcam Face Detection Demo (with FPS!) 😎
--------------------------------------------------

This is a fun little C++ project using OpenCV to:

✅ Open your MacBook's built-in camera  
✅ Mirror the video like a real-life mirror  
✅ Detect faces in real-time  
✅ Display a smooth FPS counter in the corner

Perfect for anyone learning OpenCV, C++, or just curious how to hook into your webcam and do cool stuff.

📂 Project Structure
---------------------
.
├── src/
│   └── main.cpp                ← The magic happens here
├── data/
│   └── haarcascade_frontalface_default.xml ← Face detection model
├── Makefile                    ← Just type `make run` and you're golden
├── build/                      ← Compiled object files go here (auto-created)
├── bin/                        ← Final executable lands here (auto-created)

🚀 How to Run
--------------
1. Install OpenCV via Homebrew:
   brew install opencv

2. Clone this repo

3. Build and run it:
   make run

   *(If `make` doesn't work, try setting this first:  
   `export PKG_CONFIG_PATH="/opt/homebrew/opt/opencv/lib/pkgconfig"`)*

4. Look into the camera and say hi 👋

🧠 Features
------------
- Face detection using Haar Cascades
- Realtime FPS display
- Cleanly structured C++ code
- Works great on Mac M1!

📌 Requirements
---------------
- macOS (Tested on Apple Silicon M1)
- OpenCV 4.x
- g++ / clang++
- A webcam and a smile 😊

🔧 To Do
---------
- [ ] Add face recognition (with names!)
- [ ] Record video to file
- [ ] Use DNN for better detection accuracy

🙌 Credit
----------
Uses OpenCV and their built-in Haar classifiers  
Project by [your name or handle]

---

Press ESC to exit the video window.
Enjoy hacking and happy coding! 🎉
