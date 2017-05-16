#include <ctime>
#include <iostream>
#include <raspicam_cv.h>

using namespace cv;
using namespace std;
 
int main(int argc, char **argv)
{
	raspicam::RaspiCam_Cv cam;
	Mat image;
	cam.set(CV_CAP_PROP_FORMAT, CV_8UC1);
	if (!cam.open())
		return 1;
	    
	const char szSourceWindow[] = "Source";
	namedWindow(szSourceWindow, WINDOW_AUTOSIZE);

	for (;  ;)
	{
		cam.grab();
		cam.retrieve(image);
		imshow(szSourceWindow, image);
		waitKey(100);
		    
	}
	    
	cam.release();
	return 0;
}
