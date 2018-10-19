# opencv_detect_maskers
**detection**
![detect](https://github.com/qyzhizi/opencv_detect_maskers/blob/master/053.png?raw=true)
```
enum  	cv::aruco::PREDEFINED_DICTIONARY_NAME { 
  cv::aruco::DICT_4X4_50 = 0, 
  cv::aruco::DICT_4X4_100, 
  cv::aruco::DICT_4X4_250, 
  cv::aruco::DICT_4X4_1000, 
  cv::aruco::DICT_5X5_50, 
  cv::aruco::DICT_5X5_100, 
  cv::aruco::DICT_5X5_250, 
  cv::aruco::DICT_5X5_1000, 
  cv::aruco::DICT_6X6_50, 
  cv::aruco::DICT_6X6_100, 
  cv::aruco::DICT_6X6_250, 
  cv::aruco::DICT_6X6_1000, 
  cv::aruco::DICT_7X7_50, 
  cv::aruco::DICT_7X7_100, 
  cv::aruco::DICT_7X7_250, 
  cv::aruco::DICT_7X7_1000, 
  cv::aruco::DICT_ARUCO_ORIGINAL 
}
 	Predefined markers dictionaries/sets Each dictionary indicates the number of bits and the number of markers contained
```

```
	int dictionaryId=0;// choose dict
	// cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250); 
	Ptr<aruco::Dictionary> dictionary =aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME(dictionaryId));
	while (capr.grab()) { 
		cv::Mat image, imageCopy;
		capr.retrieve(image); 
		image.copyTo(imageCopy);
		std::vector<int> ids; 
		std::vector<std::vector<cv::Point2f> > corners; 
		cv::aruco::detectMarkers(image, dictionary, corners, ids);//detect image to get the corners(vertor) and ids(number)
		cout << "corners.size()= "<< corners.size()<< endl;
		cout << "ids= "<< ids.size() <<endl;
		int size_ids = ids.size();
		// if at least one marker detected 
		if ( size_ids > 0) {
			cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);//draw bbox 
			// cout<<1<<endl;
			cout<< "ids.size() = "<< ids.size() << endl ;
			cout<<"corners.size = "<<corners.size() << endl;
			int cornersSize=corners.size();
			if(cornersSize>0){
				// int i=corners[0].size();
				cout <<"corners[0].size = "<< corners[0].size() << endl;
				cout<< "corners[0][0] = "<< corners[0][0].x<<endl;//get the first masker's first point
			}	
				//cout << corners[0].size()<<endl;
				// for(int k=0; k<cornersSize; k++){          //goes through all cv::Point2f in the vector
				// float x = corners[k].x;   //first value
				// float y = corners[k].y;   //second value
				// //stuff
				// }
		}
	cv::imshow("out", imageCopy); 
```
