#include "image_encoder.h"
#include <fstream>

void ImageEncoder::encoder2vetor(const vector<string> &img_path, vector<vector<int> > &img_codes)
{
	//ofstream t("out.txt");
	for (int i = 0; i != img_path.size();++i)
	{
		string tmp = img_path[i];
		cout<<tmp<<endl;
		Mat img=imread(tmp);
		if (!img.data)
		{
			ProGif pg(1);
			vector<Mat> gif_frames;
			pg.pickGif2Mats(tmp.c_str(), 1, gif_frames);
			if(!gif_frames.empty()) img = gif_frames[0];
		}
		if (!img.data)
		{
			cout << "can not read image" << endl;
			//t << tmp << endl;
			continue;
		}

		Mat img_pro;
		img_prep.ImgResize(img, img_pro, obj_len);
		vector<int> code;
		img_prep.imgRGB_HSVQuantization(img_pro, code);
		img_codes.push_back(code);
	}

	//t.close();
}

void ImageEncoder::encoder2vetor(const vector<string> &img_path, vector<vector<vector<int> > > &img_codes)
{
	//ofstream t("out.txt");
	for (int i = 0; i != img_path.size(); ++i)
	{
		string tmp = img_path[i];
		cout << tmp << endl;
		Mat img = imread(tmp);
		if (!img.data)
		{
			ProGif pg(1);
			vector<Mat> gif_frames;
			pg.pickGif2Mats(tmp.c_str(), 1, gif_frames);
			if (!gif_frames.empty()) img = gif_frames[0];
		}
		if (!img.data)
		{
			cout << "can not read image" << endl;
			//t << tmp << endl;
			continue;
		}
		if (img.rows < 50 || img.cols < 50) continue;

		Mat img_pro;
		img_prep.ImgResize(img, img_pro, obj_len);
		vector<vector<int> > code;
		img_prep.imgRGB_HSVQuantization(img_pro, code);
		img_codes.push_back(code);
	}

	//t.close();
}
