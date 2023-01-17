# Qt_Unity

The project is about integration of Unity application in QtQml

In unity the applications is first build and then it is integrated in Qt.
The steps needed for this are:
1. Build Unity project as general Desktop application with the general input controls.

2. After builiding and the exe seems to be working fine without any errors.

3. create a Qt widget application where you can integrate the unity exe in your Qt by following
this link https://gist.github.com/jbltx/db1f4df72654e2b2339956758ee0ce34

4. Inside your Qt application create a server using TCP connection to send data to the unity side.

5. After that create unity as TCP client connection in unity and change the controls based on the input from tcp client connection.
