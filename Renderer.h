class Renderer {
  public:
    Renderer(SDL_Renderer* renderer);
    virtual void render() {};
    ~Renderer();
  protected:
    SDL_Renderer* rootRenderer;
};
