// TextBlock

#ifndef _TextBlock
#define _TextBlock


struct TextBlock
{
	TextBlock() = default;
	TextBlock(const TextBlock&) = delete;
	TextBlock& operator=(const TextBlock&) = delete;
	~TextBlock() = default;

	void SetRowCol(int row, int col);

	int row;
	int col;
};


#endif _TextBlock
