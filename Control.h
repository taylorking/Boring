class Control {
  public: 
    ~Control();
    Control(Entity* controlled);
    void poll();
  private:
    Entity* controlled;
};
