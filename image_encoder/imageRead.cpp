#include "imageRead.h"

int readImageFile(string &imageFile, vector<string> &pathOfImage)
{
	string buf;
	int imageCount = 0;

	ifstream img_list(imageFile.c_str());

	if (img_list)
	{
		cout << "file is : " << imageFile << endl;

	}
	else
	{
		cout << "cannot open the imagelist file." << endl;
	}

	while (img_list)
	{
		if (getline(img_list, buf))
		{
			pathOfImage.push_back(buf);
			imageCount++;
		}
	}
	img_list.close();
	cout << imageCount << " things have been read" << endl;

	return imageCount;
}

