class EntityRenderer: public Renderer {
  public:
    ~EntityRenderer();
    EntityRenderer(SDL_Renderer* r);
    void render();
    void renderPlayer();
    void renderNonPlayers();
};
