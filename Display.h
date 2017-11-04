class Display {
  public: 
    Display(std::string title);
    ~Display();
    void playIntro();
    void update();
    void drawEntity(Entity* entity);
  private:
    SDL_Window* window;
};
