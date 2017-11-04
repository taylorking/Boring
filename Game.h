class Game {
  public: 
    Game();
    ~Game();
    void start();
    State* getState();
  private:
    Display* video;
    Control* control;
    State* state;
};
