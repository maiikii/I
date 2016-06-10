#include <SFML/Graphics.hpp>

class AniSprite : public sf::Sprite{
public:
	AniSprite();
		//initialtion list

	AniSprite(const sf::Texture& Img, int frameWidth, int frameHeight);
	~AniSprite(void);
	//Get
	sf::IntRect GetFramePosition(int frame);
	int GetFrameCount();
	//set
	void SetFrameSize(int frameWidth, int frameHeight);
	//Sets current frame
	void SetFrame(int frame);
	//sets loop speed in fps
	void SetLoopSpeed(float fps);
	//start looping
	void Play();
	void Play(int start, int end);
	//stop
	void Stop();
	//draw functions
	void Update();
private:
	sf::Clock clock;
	float fps;
	bool isPlaying;
	int loopStart;
	int loopEnd;
	int currentFrame;
	int frameWidth;
	int frameHeight;
};

AniSprite::AniSprite() : sf::Sprite() {
	this->fps=1;
	this->currentFrame=0;
	this->isPlaying = false;
	this->loopStart = 0;
	this->SetFrameSize(0, 0);
}

AniSprite::AniSprite(const sf::Texture& Img, int frameW, int frameH) : sf::Sprite(Img){
	this->fps=1;
	this->currentFrame=0;
	this->isPlaying = false;
	this->loopStart = 0;
	this->SetFrameSize(frameW, frameH);
	//now calculate stuff
}

AniSprite::~AniSprite(void){

}

int AniSprite::GetFrameCount(){
	unsigned int across = this->getTextureRect().width/this->frameWidth;
	unsigned int down = this->getTextureRect().height/this->frameHeight;

	return across*down;
}
//first frame is frame ZERO
sf::IntRect AniSprite::GetFramePosition(int frame){
	//get number across and down
	unsigned int across = (this->getTextureRect().width/this->frameWidth);
	unsigned int down = (this->getTextureRect().height/this->frameHeight);

    int tileY = frame / across ; //get Y on grid
    int tileX = frame % across ; //get X on grid

	sf::IntRect result(
		tileX*this->frameWidth,
		tileY*this->frameHeight,
		tileX*this->frameWidth + this->frameWidth,
		tileY*this->frameHeight + this->frameHeight);
	//end
	return result;

}
//
void AniSprite::SetFrameSize(int frameW, int frameH){
	this->frameWidth = frameW;
	this->frameHeight = frameH;
	this->setTextureRect(sf::IntRect(0,0,frameW,frameH));
}
//Sets current frame
void AniSprite::SetFrame(int frame){
	this->currentFrame = frame;
}
//sets loop speed in fps
void AniSprite::SetLoopSpeed(float newfps){
	this->fps = newfps;
}
//start looping
void AniSprite::Play(){
	this->Play(0,GetFrameCount());
}

void AniSprite::Play(int start, int end){
	loopStart = start;
	loopEnd = end;
	currentFrame = start;
	isPlaying = true;
	clock.restart();
}
//stop
void AniSprite::Stop(){
	isPlaying = false;
}
//update function
void AniSprite::Update(){
	if(isPlaying){
		int frameCount = loopEnd - loopStart;
		float timePosition = (clock.getElapsedTime().asMilliseconds() * fps);
		currentFrame = loopStart + (int)timePosition % frameCount;
		//printf("%f:%i\n",clock.GetElapsedTime(),currentFrame);

		this->setTextureRect(GetFramePosition(currentFrame));
	}
}
