<h1 style="text-align:center;">🎯 Investigation & Enhancement of the 2048 Game Project</h1>

<p style="text-align:center;">
  A <strong>deep-dive investigation</strong> into the 2048 Game and our comprehensive improvements—covering functionality, limitations, and future possibilities.
</p>

<hr>

<h2>🔍 Original Project Overview</h2>
<p>
  The original <strong>2048 game</strong> is a console-based puzzle where the player slides numbered tiles on a grid to combine them and eventually reach the value <strong>2048</strong>. It uses simple text output enriched with ANSI color codes for vibrant visual feedback.
</p>

<hr>

<h2>⚙️ Key Features & Mechanics</h2>

<h3>🗺️ Board Setup & Initialization</h3>
<ul>
  <li><strong>Grid Structure:</strong> Uses a 2D grid (usually 4×4) where empty cells are represented as <code>0</code>.</li>
  <li><strong>Starting Tiles:</strong> Begins with one or two randomly placed tiles (typically, 2's).</li>
</ul>

<h3>🔄 Tile Movement & Merging</h3>
<ul>
  <li><strong>Movement:</strong> Tiles shift in the chosen direction (<strong>W/A/S/D</strong> or arrow keys) until they hit an obstacle.</li>
  <li><strong>Combination:</strong> When two adjacent tiles with the same value meet, they merge into one (doubling the value) and update the score.</li>
  <li><strong>Two-Phase Approach:</strong> First <em>move</em> then <em>combine</em> — ensuring the game logic remains predictable.</li>
</ul>

<h3>✨ New Tile Generation</h3>
<ul>
  <li><strong>Dynamic Spawning:</strong> After each valid move, a new tile (2 or 4, based on a set probability) is added randomly.</li>
</ul>

<h3>🎮 Input Handling & Game Flow</h3>
<ul>
  <li><strong>Supported Commands:</strong>
    <ul>
      <li>WASD / Arrow Keys for directional moves</li>
      <li>Pause: <code>p</code></li>
      <li>Undo: <code>u</code></li>
      <li>Restart: <code>r</code></li>
      <li>Quit: <code>q</code></li>
    </ul>
  </li>
  <li><strong>Smooth Flow:</strong> Seamless transitions between input commands and game state updates.</li>
</ul>

<h3>🎨 Visual Feedback</h3>
<ul>
  <li><strong>ANSI Color Coding:</strong> Provides clear visual differentiation for tiles.</li>
  <li><strong>On-Screen Indicators:</strong> A prominent score display and turn counter.</li>
</ul>

<h3>🏆 Leaderboard</h3>
<ul>
  <li><strong>Score Persistence:</strong> Game scores are saved in <code>leaderboard.txt</code> for historical tracking.</li>
</ul>

<p><strong>References:</strong></p>
<ul>
  <li>Game logic & rendering – <code>game.cpp</code></li>
  <li>Class structure – <code>game.h</code></li>
  <li>Leaderboard – <code>leaderboard.txt</code></li>
  <li>Input & main loop – <code>main.cpp</code></li>
</ul>

<hr>

<h2>🚧 Limitations of the Original Code</h2>
<ul>
  <li><strong>Basic Visuals:</strong> Lacks advanced animations and dynamic transitions.</li>
  <li><strong>Input Handling Robustness:</strong> Rapid inputs or ambiguous commands may lead to unexpected behavior.</li>
  <li><strong>Limited Undo Feature:</strong> The hard-coded undo limit (5 moves) can restrict the user experience.</li>
  <li><strong>Code Structure:</strong> Mixing of game logic, rendering, and control flow complicates future expansion.</li>
  <li><strong>Extensibility:</strong> Monolithic design restricts integration of features like sound effects, enhanced UI, or networked play.</li>
</ul>

<hr>

<h2>🔧 Our Code Improvements Explained</h2>
<p>
  Our modifications address these limitations by refining functionality, robustness, and the overall developer/user experience.
</p>

<h3>✅ Enhanced Game State Management</h3>
<ul>
  <li><strong>Robust Undo System:</strong> Before every move, the entire game state (board, score, turn) is saved into an <strong>undo stack</strong>. Seamless rollback reduces the risk of state corruption. <em>(Implementation details in <code>game.cpp</code>.)</em></li>
</ul>

<h3>✅ Refined Input Handling & Control Flow</h3>
<ul>
  <li><strong>Structured Command Processing:</strong> Commands such as pause, undo, restart, and quit are clearly handled. Improved checks ensure rapid or multiple inputs do not disrupt game state.</li>
  <li><strong>User Feedback Enhancements:</strong> Auditory cues (a beep) confirm valid moves and clear on-screen notifications indicate events like pause or restart. <em>(See <code>main.cpp</code> for details.)</em></li>
</ul>

<h3>✅ Improved Code Organization & Readability</h3>
<ul>
  <li><strong>Separation of Concerns:</strong> Better modularity between game logic and UI rendering allows independent modifications.</li>
  <li><strong>Clear Function Responsibilities:</strong> Methods like <code>move()</code> and <code>combine()</code> have been refactored for clarity.</li>
  <li><strong>Comprehensive Documentation:</strong> Enhanced inline comments and naming conventions aid future maintenance.</li>
</ul>

<h3>✅ Leaderboard & Persistence Enhancements</h3>
<ul>
  <li><strong>Score Tracking:</strong> Scores are appended to and sorted from <code>leaderboard.txt</code> to maintain a history. The leaderboard display now makes high scores easy to interpret.</li>
</ul>

<h3>✅ Future-Proofing & Extensibility</h3>
<ul>
  <li><strong>Modular Design:</strong> Lays the groundwork for transitioning to GUI-based implementations (e.g., using SDL or SFML).</li>
  <li><strong>Feature Expansion:</strong> Ready for future additions like sound effects, animations, advanced control options, and even online play.</li>
  <li><strong>Dynamic Options:</strong> Possibility to implement dynamic difficulty settings or alternate board sizes.</li>
</ul>

<hr>

<h2>🎉 Future Roadmap</h2>
<ul>
  <li><strong>Graphical User Interface (GUI):</strong> Transition to a GUI for smoother animations and a richer user experience.</li>
  <li><strong>Sound & Effects:</strong> Integrate custom sound effects and background music.</li>
  <li><strong>Flexible Undo/Replay:</strong> Implement a dynamic undo mechanism or a replay feature.</li>
  <li><strong>Expanded Game Modes:</strong> Offer multiple board sizes, various difficulty levels, or even a competitive networked version.</li>
  <li><strong>Enhanced Persistence:</strong> Migrate from a text file to a database or online leaderboard system.</li>
</ul>

<hr>

<h2>🏆 Conclusion</h2>
<p>
  The original 2048 game laid a solid foundation with its minimalist design. Our improvements focus on:
</p>
<ul>
  <li><strong>Robust State Management:</strong> Enabling a reliable undo system.</li>
  <li><strong>Refined Input Handling:</strong> Delivering a smoother, more intuitive experience.</li>
  <li><strong>Separation of Concerns:</strong> Enhancing maintainability and paving the way for future feature integration.</li>
  <li><strong>Future-Ready Enhancements:</strong> Preparing the codebase for GUI transitions, advanced animations, sound, and online capabilities.</li>
</ul>

<hr>

<p><strong>Prepared by [Your Name/Group] — [Date]</strong></p>
<p><em>Thank you for exploring our enhanced 2048 game project! We welcome your feedback and contributions to further refine this classic game.</em></p>

<hr>

<h2>Multimedia Showcase</h2>

<h3>Screenshots</h3>
<p>
  <img src="./assets/images/WhatsApp_Image_2025-04-16_at_23.16.20.jpg" alt="Enhanced 2048 Screenshot 1" width="600">
</p>
<p>
  <img src="./assets/images/WhatsApp_Image_2025-04-16_at_23.29.01.jpg" alt="Enhanced 2048 Screenshot 2" width="600">
</p>

<h3>Video Demo</h3>
<p>
  <video width="600" controls>
    <source src="./assets/videos/WhatsApp_Video_2025-04-16_at_23.26.26.mp4" type="video/mp4">
    Your browser does not support the video tag.
  </video>
</p>
