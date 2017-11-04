class Display {
  public: 
    Display(std::string title);
    ~Display();
    void playIntro();
    void update();
    void drawEntity(Entity* entity);
    void drawLevelEnvironment(Level* level);
  private:
    SDL_Window* window;
};
