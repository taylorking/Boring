class Game {
  public: 
    Game();
    ~Game();
    void start();
  private:
    Display* video;
    Control* control;
};
