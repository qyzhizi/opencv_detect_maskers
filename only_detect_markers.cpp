#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
// #include <opencv2/opencv.hpp> 
#include <iostream>
using namespace std;
using namespace cv;



int main(int argc, char *argv[]) {

//  cv::VideoCapture capr; 
//  capr.open(0); 
	cv::VideoCapture capr(1);  //right_cam
	if (!capr.isOpened()) {
			cerr << "ERROR! Unable to open camera\n";
			return -1;
		 }
		//设置右相机的输出格式
	capr.set(CV_CAP_PROP_FPS, 30);  
	capr.set(CV_CAP_PROP_FRAME_WIDTH, 1280);  //640 1280
	capr.set(CV_CAP_PROP_FRAME_HEIGHT, 720);//480 720
	capr.set(CAP_PROP_FOURCC,CV_FOURCC('M', 'J', 'P', 'G'));

	int dictionaryId=10;//DICT_6X6_250
	// cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250); 
	Ptr<aruco::Dictionary> dictionary =aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME(dictionaryId));
	while (capr.grab()) { 
		cv::Mat image, imageCopy;
		capr.retrieve(image); 
		image.copyTo(imageCopy);
		std::vector<int> ids; 
		std::vector<std::vector<cv::Point2f> > corners; 
		cv::aruco::detectMarkers(image, dictionary, corners, ids);
		cout << "corners.size()= "<< corners.size()<< endl;
		cout << "ids= "<< ids.size() <<endl;
		int size_ids = ids.size();
		// if at least one marker detected 
		if ( size_ids > 0) {
			cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
			// cout<<1<<endl;
			cout<< "ids.size() = "<< ids.size() << endl ;
			cout<<"corners.size = "<<corners.size() << endl;
			int cornersSize=corners.size();
			if(cornersSize>0){
				// int i=corners[0].size();
				cout <<"corners[0].size = "<< corners[0].size() << endl;
				cout<< "corners[0][0] = "<< corners[0][0].x<<endl;
			}	
				//cout << corners[0].size()<<endl;
				// for(int k=0; k<cornersSize; k++){          //goes through all cv::Point2f in the vector
				// float x = corners[k].x;   //first value
				// float y = corners[k].y;   //second value
				// //stuff
				// }
		}
	cv::imshow("out", imageCopy); 
	char key = (char) cv::waitKey(0); 
	if (key == 27) break; 

	}
}