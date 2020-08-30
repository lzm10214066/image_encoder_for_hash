#include <opencv2/opencv.hpp>
#include <iostream>

#include "image_encoder.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	vector<string> image_path;
	ImageEncoder img_encoder;
	image_path.push_back("tt.gif");
	image_path.push_back("2.webp");
	image_path.push_back("1.webp");
	image_path.push_back("3.webp");
	image_path.push_back("2.webp");
	//vector<vector<int> > img_codes;
	vector<vector<vector<int> > > img_codes;
	double t = (double)getTickCount();

	img_encoder.encoder2vetor(image_path,img_codes);
	cout<<img_codes.size()<<endl;

	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "Times passed in ms: " << t * 1000 << endl;

	/*	string folderName = "res";
		for (int i = 0; i < gif_frames.size(); ++i)
		{
		char srcToSaved[500];
		string name = getFileName(s);
		sprintf(srcToSaved, "%s/%s_%d.png", folderName.c_str(), name.c_str(), i);
		string tt(srcToSaved);
		imwrite(srcToSaved, gif_frames[i]);
		}*/


	return 0;
}


