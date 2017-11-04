class EntityRenderer : public Renderer {
  public:
    ~EntityRenderer();
    EntityRenderer(SDL_Renderer* renderer);
    void render();
    void renderPlayer();
    void renderNonPlayers();
};
