### Functional Requirements
1. Start a new game with two players.
2. Make a move and validate it (check for valid positions and turns).
3. Determine the game result (win, lose, or draw).
4. Allow retrieval of the game state at any point.
5. Handle multiple simultaneous games.

### Non-Functional Requirements
1. Scalability: Handle multiple active games concurrently.
2. Performance: Optimize response times for move validations and game state checks.
3. Reliability: Ensure game state is consistent even in case of server failures.
4. Security: Prevent unauthorized access or invalid requests (e.g., invalid moves).
5. Extensibility: Allow easy addition of new features (e.g., AI opponent, larger grids).

### Database Design

1. Player
- name
- id
- email

2. Move
- id
- game_id (Foreign Key)
- player_id (Foreign Key)
- row
- col

3. Game
- id
- player_1 (Foreign Key)
- player_2 (Foreign Key)
- current_player
- status enum(ONGOING, WIN, DRAW)
- winner_id

### APIs
1. Start a new game\
POST /start-game\
Request \
{\
    "player1": "Alice",\
    "player2": "Bob\
}

2. Make a move\
POST /make-move

3. Get status\
GET /game-status\
Request Params: ?game_id=1




