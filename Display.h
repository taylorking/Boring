class Display {
  public: 
    Display(std::string title);
    ~Display();
    void playIntro();
    void update();
  private:
    SDL_Window* window;
};
