🎥 OpenCV Webcam Face Detection Demo (with FPS!) 😎
--------------------------------------------------

This is a fun little C++ project using OpenCV to:

✅ Open your MacBook's built-in camera  
✅ Mirror the video like a real-life mirror  
✅ Detect faces in real-time  
✅ Display a smooth FPS counter in the corner

<img src="https://github.com/user-attachments/assets/9e13adbc-8252-479e-9a63-b7d9f9bc3a73" alt="Webcam Demo" width="400"/>

📂 Project Structure
---------------------
```.
├── src/
│   └── main.cpp                
├── data/
│   └── haarcascade_frontalface_default.xml ← Face detection model
├── Makefile                    ← Just type `make run`
├── build/                      ← Compiled object files go here (auto-created)
├── bin/                        ← Final executable lands here (auto-created)
```
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

🙌 Credit
----------
Uses OpenCV and their built-in Haar classifiers  


---

Press ESC to exit the video window.
🎉🎉🎉🎉
