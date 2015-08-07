<TeXmacs|1.99.2>

<style|<tuple|book|style>>

<\body>
  <doc-data|<doc-title|Programming Practice Report>|<doc-subtitle|of Software
  Engineering School>|<doc-author|<author-data|<author-name|<tabular|<tformat|<cwith|1|-1|1|1|cell-hyphen|n>|<cwith|1|-1|1|1|cell-halign|r>|<table|<row|<cell|Subject>|<cell|>|<cell|<with|font-shape|right|<with|font|concrete|Line
  Planner>>>>|<row|<cell|Author>|<cell|>|<cell|<with|font|concrete|Weiju Lan>
  <with|font|fireflysung|(\<#5170\>\<#5A01\>\<#4E3E\>)>>>|<row|<cell|Major>|<cell|>|<cell|<with|font-shape|right|<with|font|concrete|Software
  Engineering>>>>|<row|<cell|Class>|<cell|>|<cell|<with|font-shape|right|<with|font|concrete|2013
  Class 1>>>>|<row|<cell|Id>|<cell|>|<cell|<with|font|concrete|<verbatim|13108115>>>>>>>>>>>

  <\table-of-contents|toc>
    <vspace*|1fn><with|font-series|bold|math-font-series|bold|1<space|2spc>Design>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-1><vspace|0.5fn>

    1.1<space|2spc>Goals <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-2>

    <with|par-left|1tab|1.1.1<space|2spc>The TUI
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-3>>

    <with|par-left|1tab|1.1.2<space|2spc>The Planner
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-4>>

    1.2<space|2spc>Decisions <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-5>

    <with|par-left|1tab|1.2.1<space|2spc>Only Lines Have Directions
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-6>>

    <with|par-left|1tab|1.2.2<space|2spc>No Direction Change When Searching
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-7>>

    <with|par-left|1tab|1.2.3<space|2spc>Stops Are Visited Only Once
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-8>>

    <with|par-left|1tab|1.2.4<space|2spc>Only Display Least Changes
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-9>>

    <with|par-left|1tab|1.2.5<space|2spc>Use
    <with|font-family|tt|language|verbatim|glibc> for
    <with|font-family|tt|language|verbatim|UTF-8> Handling
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-10>>

    <with|par-left|1tab|1.2.6<space|2spc>Use
    <with|font-family|tt|language|verbatim|graphviz> for Graph Visualization
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-11>>

    <vspace*|1fn><with|font-series|bold|math-font-series|bold|2<space|2spc>Implementation>
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-12><vspace|0.5fn>

    2.1<space|2spc>Overview <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-13>

    2.2<space|2spc>Challenges <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-15>

    <with|par-left|1tab|2.2.1<space|2spc>Route Planning
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-16>>

    <with|par-left|1tab|2.2.2<space|2spc>Unicode Handling
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-17>>

    <with|par-left|1tab|2.2.3<space|2spc>The TUI
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-18>>

    <with|par-left|1tab|2.2.4<space|2spc>File Changes Monitoring
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-20>>

    <with|par-left|1tab|2.2.5<space|2spc>Signal Handling
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-21>>

    <with|par-left|1tab|2.2.6<space|2spc>Presentation of Plans
    <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-22>>

    <vspace*|1fn><with|font-series|bold|math-font-series|bold|3<space|2spc>Summary
    and Thoughts> <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
    <no-break><pageref|auto-23><vspace|0.5fn>
  </table-of-contents>

  <chapter|Design>

  <section|Goals>

  The <verbatim|line planner> is designed to be a <term|TUI|Text User
  Interface> application for <verbatim|modern Linux>. It's designed to be
  <emp|modern>, <emp|robust>, <emp|signal-aware> and <emp|linux-only>. The
  whole project is written in <verbatim|GNU C++14>.

  The <verbatim|line planner> should parse the line/stop information from a
  table-like file and should reparse the file when it is changed by other
  applications like a text editor. The user should be able to search for the
  passing stops of a line and the passing lines of a stop. And it should be
  able to plan routes for the user between 2 stops within 2 changes of lines
  (i.e. on 3 lines most). The application should respect the use habits of a
  serious linux user, which means, it should cancel the current blocking
  operation or exit in a user-friendly way when the user hit <verbatim|^c>
  (a.k.a. hold the <verbatim|control> key and hit the lower--case letter
  <verbatim|c>), and it should force quit <emp|abnormally> when the user
  smashes <verbatim|^c>.

  Only the plans that have the least line-changes are kept and displayed to
  the user. The result will be sorted in an ascending manner by the number of
  stops the lines pass by in the plan. When the user want to see details of a
  plan, a graph should be generated and displayed on the screen.

  <subsection|The TUI>

  The TUI should be <emp|modern> and straightforward like a web browser. It
  should have only 1 modal interface displaying the line/stop information or
  the plan list/details.

  The TUI should be able to display and input <verbatim|UTF-8>-encoded
  Unicode (mostly Chinese) characters. The size/dimension of the UI should
  not be hard-coded, it should be responsive to the terminal size.

  <subsection|The Planner>

  The planner is responsible for parsing the line/stop information file, and
  restructure the data into a planner state. It then should be able to plan
  the route using that state.

  The goal of restructuring the data is to make the later queries easier to
  do. Thus the data should be restructured into some <em|associative arrays>
  and some sort of <em|adjacent table> of a graph.

  The route planning is done by doing an optimized <em|depth-first search> of
  the graph in the planner state generated by the data parser.

  \;

  \;

  \;

  <section|Decisions>

  <subsection|Only Lines Have Directions>

  Both the lines and stops provided in the data file have a direction
  associated. In this application, the direction of a line is <em|kept>,
  while stops having the same name but differs in directions are <em|merged>
  into one stop.

  <subsection|No Direction Change When Searching>

  When doing the route planning by searching the graph, the direction won't
  change if the line is not changed.

  <subsection|Stops Are Visited Only Once>

  Stops are visited exactly once in each plan.

  <subsection|Only Display Least Changes>

  Only lines that have least changes are displayed. If there is a direct
  line, lines with 1 change will not be displayed, even if there is one.

  <subsection|Use <verbatim|glibc> for <verbatim|UTF-8> Handling>

  There is Unicode support since <verbatim|C++11>, but <verbatim|libstdc++>
  (the default <verbatim|C++> standard library on most linux systems) did
  <strong|NOT> implement it. There are 2 alternatives: either use the
  <verbatim|GNU C> standard library <verbatim|glibc> or use <verbatim|libc++>
  from <verbatim|clang>. <verbatim|glibc> is chosen for smaller footprint.

  <subsection|Use <verbatim|graphviz> for Graph Visualization>

  <verbatim|graphviz dot> is used to generate the eye-pleasing graph image of
  the plan returned by the route planner.

  <chapter|Implementation>

  <section|Overview>

  <\itemize>
    <item>The whole project uses <verbatim|git> to do the version control

    <item>The building system uses a custom one of mine, which includes a
    <verbatim|perl>-written <verbatim|configure> script that generates
    <verbatim|GNU makefile>. Then the actual building is coordinated by
    <verbatim|GNU make>, which calls <verbatim|clang++> to build the whole
    application.

    <item>The whole project is scanned by <verbatim|clang static analyzer> in
    order to discover and eliminate static bugs.

    <item>The application is written in <verbatim|GNU C++14>, using
    <verbatim|ncursesw> to support the TUI. The <verbatim|w> version of the
    <verbatim|ncurses> library supports Unicode <verbatim|UCS-4> encoding,
    which then can be converted into <verbatim|UTF-8>.

    <item><verbatim|ANSI Escape Sequences> is used for setting the title of X
    virtual terminals like <verbatim|gnome terminal>.

    <item>Designed with <verbatim|C++>'s multi-paradigm in mind. Using
    <term|POP|Procedure-Oriented Programming>, <term|FP|Functional
    Programming>, <term|GP|Generic Programming> and
    <term|MP|Meta-Programming> techniques.
  </itemize>

  <big-figure|<verbatim|<tabular|<tformat|<table|<row|<cell|line-planner>|<cell|>|<cell|>>|<row|<cell|\|----------->|<cell|main>|<cell|>>|<row|<cell|\|----------->|<cell|mixin>|<cell|>>|<row|<cell|\|----------->|<cell|signal>|<cell|>>|<row|<cell|\|----------->|<cell|utf8>|<cell|>>|<row|<cell|\|----------->|<cell|watch>|<cell|>>|<row|<cell|\|----------->|<cell|ui>|<cell|>>|<row|<cell|\|>|<cell|\|------>|<cell|context>>|<row|<cell|\|>|<cell|\|------>|<cell|style>>|<row|<cell|\|>|<cell|\|------>|<cell|widget>>|<row|<cell|\|>|<cell|\|------>|<cell|choose>>|<row|<cell|\|>|<cell|\|------>|<cell|edit>>|<row|<cell|\|>|<cell|\|------>|<cell|list>>|<row|<cell|\|>|<cell|\|------>|<cell|search>>|<row|<cell|\|>|<cell|\|------>|<cell|linestop>>|<row|<cell|\|>|<cell|\|------>|<cell|plan>>|<row|<cell|\|>|<cell|\|------>|<cell|stage>>|<row|<cell|\|----------->|<cell|planner>|<cell|>>|<row|<cell|>|<cell|\|------>|<cell|state>>|<row|<cell|>|<cell|\|------>|<cell|parser>>|<row|<cell|>|<cell|\|------>|<cell|plan>>>>>>|Components>

  <section|Challenges>

  <subsection|Route Planning>

  This is in fact the simplest part of this program, just do a
  <term|DFS|depth-first search> and everything is done. Stops are vertices,
  and a transition is an edge.

  There is some modification in the DFS algorithm. Since only the lines with
  least changes is needed, lines with change count larger than the already
  found ones are skipped, and when a line with less changes is found, the
  already found ones are cleared.

  <subsection|Unicode Handling>

  In linux, Unicode is encoded in <verbatim|UTF-8> variable length encoding,
  which is byte-stream oriented, making it simple to integrate into
  <verbatim|char string> but difficult to calculate length/width and edit.

  In terminals, texts are displayed in a grid, each English letter taking up
  one cell of the grid. But some characters like the Chinese ones need 2
  horizontally adjacent cells. The width of a <verbatim|UTF-8 string> is
  needed to proper align texts in terminals. Because of the length-varying
  nature of <verbatim|UTF-8>, it cannot be done by just counting the number
  of bytes nor codepoints in the string.

  The way to do this is tricky: convert <verbatim|UTF-8 string> to
  <verbatim|UCS-4 string>, then calculate its width using
  <verbatim|wcswidth(3)> (conforming to the standard
  <verbatim|POSIX.1-2001>). Before calling <verbatim|wcswidth>,
  <verbatim|std::setlocale> must be called to setup <verbatim|LC_CTYPE> to
  the system's locale.

  Editing is done similarly. To remove last character, convert it to
  <verbatim|UCS-4 string> and then <verbatim|pop_back> the last codepoint. To
  fill gaps, do it the same way.

  Other operations like fixing the width of the <verbatim|string> are done in
  the same way.

  To support the input of Unicode, the <verbatim|w> version of
  <verbatim|ncurses> (i.e. <verbatim|ncursesw>) is used. The
  <verbatim|getch(3)> is replaced by <verbatim|get_wch(3)> to input
  <verbatim|UCS-4 char> (i.e. <verbatim|wchar_t>, which is a <verbatim|32-bit
  fixed- point number>), and then it is converted to <verbatim|UTF-8 string>
  for further processing.

  \;

  <subsection|The TUI>

  All the low-level call to <verbatim|ncursesw> is wrapped in
  <verbatim|struct context> to hide the ugly <verbatim|namespace-less>
  <verbatim|C> interface of the library.

  All the rendering is manually done. The TUI is designed to be themable (in
  <verbatim|style> module) and composible in a <em|functional> (as in
  functional programming) manner. The <verbatim|std::initializer_list> is
  exploited in some places (e.g. <verbatim|choose> and <verbatim|list>) to
  make life easier.

  <big-table|<verbatim|<tabular|<tformat|<cwith|1|-1|1|1|cell-halign|r>|<table|<row|<cell|widget:>|<cell|<with|color|dark
  magenta|N/A>>>|<row|<cell|choose:>|<cell|widget>>|<row|<cell|edit:>|<cell|<with|color|dark
  magenta|N/A>>>|<row|<cell|list:>|<cell|widget>>|<row|<cell|search:>|<cell|widget,
  list, edit>>|<row|<cell|linestop:>|<cell|search>>|<row|<cell|plan:>|<cell|widget,
  search>>|<row|<cell|stage:>|<cell|widget, choose,
  linestop>>>>>>|Dependencies>

  \;

  <subsection|File Changes Monitoring>

  This application uses <verbatim|inotify(7)> mechanism provided by the Linux
  kernel to monitor the change of the data file in the filesystem.

  The directory containing the data file is monitored rather than the file
  itself, bacause the mature and robust way to save a file (like what
  <verbatim|vim> has done) is to save the file in another name and then move
  that file to override the old one. And you can no longer monitor the file
  when it has been overridden. Thus the directory is monitored with
  <verbatim|IN_CREATE \| IN_DELETE \| IN_MODIFY \| IN_MOVE> attributes in
  order to get notified when the data file is changed.

  To actual monitor it, a blocking <verbatim|read(2)> for <verbatim|struct
  inotify_event> (see <verbatim|inotify(7)>) is called with the
  <verbatim|watch descriptor> created from the <verbatim|inotify descriptor>
  created by <verbatim|inotify_init(2)>. When any event happens, the
  <verbatim|read(2)> call returns.

  Bacause it's a blocking call, in order to co-operate with other part of the
  program, the monitoring is done in another thread. <verbatim|C++> provides
  native threading support by <verbatim|std::thread>. A <verbatim|bool>
  <em|atomic> variable (<verbatim|std::atomic_bool>) is used for
  communication.

  But sometimes a blocking wait is needed, thus a <verbatim|wait_change>
  function is provided for that. It uses <verbatim|std::condition_variable>
  with <verbatim|std::mutex> and the atomic variable described above to
  achieve the waiting without wasting CPU cycles.

  <subsection|Signal Handling>

  Signals, because of its asynchronous nature, is difficult to handle. As a
  general rule of thumb: do <strong|NOT> change anything (except for
  <verbatim|std::sig_atomic_t> variables) or call any mutating function in
  signal callbacks.

  In this application, the signal callback only changes a ``quit state''
  <em|signal atomic> variable, or throws <verbatim|force_quit> when
  appropriate in order to respect the use habits of Linux terminal
  applications.

  <subsection|Presentation of Plans>

  The plan (a.k.a. the result of the route planner) ought to be presented in
  a pleasing manner. Thus, it is displayed as a graph image on the screen.

  A <verbatim|graphviz dot> script is generated for the plan and then fed
  into a little script called <verbatim|preview>, which is an
  <verbatim|sh(1)> script that calls <verbatim|dot(1)> to generate a
  <verbatim|png> image of the graph, store it in a directory as history, and
  display the image with <verbatim|feh(1)>.

  <chapter|Summary and Thoughts>

  I thought the route planning algorithm would be the most challenging part
  of the program, but no, it seems to be the simplest part. Thus it's not
  focused in this report.

  I had only written small TUIs and never tried writing medium-sized or even
  large-scale TUI application, which is rather complex and daunting, though
  not difficult. The UI part takes up <math|64%> of all the source code.

  Applying various techniques from different paradigms is really important to
  write <em|clean>, <em|simple> yet <em|readable> code in <verbatim|modern
  C++>. <term|OOP|Object-Oriented Programming> is avoided <em|deliberately>
  because it simply <strong|sucks>. <verbatim|C++> has much much superior
  resource (memory, files, etc) management method than any other programming
  language in the world, which made me stick to it.

  <verbatim|C++14> rocks. I switched to <verbatim|clang> completely, which
  has better error messages and optimization than <verbatim|GCC>, and it even
  comes with a <verbatim|static analyzer>. It's a pity that I didn't try the
  <verbatim|libc++> from <verbatim|clang> this time, I will switch to it
  soon.

  \;

  \;

  \;

  \;

  \;

  <\right-aligned>
    <tabular|<tformat|<cwith|1|1|1|1|cell-halign|c>|<table|<row|<cell|<with|font-base-size|12|<with|font|concrete|Software
    Enginnering School>>>>|<row|<cell|>>|<row|<cell|<tabular|<tformat|<cwith|1|-1|1|1|cell-halign|r>|<table|<row|<cell|<name|Class>>|<cell|>|<cell|<with|font|concrete|2013
    Class 1>>>|<row|<cell|<name|Author>>|<cell|>|<cell|<name|<with|font|concrete|Weiju
    Lan>> <with|font|fireflysung|(\<#5170\>\<#5A01\>\<#4E3E\>)>>>|<row|<cell|<name|Id>>|<cell|>|<cell|<with|font|concrete|<verbatim|13108115>>>>|<row|<cell|<name|Date>>|<cell|>|<cell|<verbatim|<with|font|concrete|2014/12/06>>>>>>>>>>>><space|2tab>
  </right-aligned>
</body>

<\initial>
  <\collection>
    <associate|font|roman>
    <associate|math-font|roman>
    <associate|page-medium|paper>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|5>>
    <associate|auto-10|<tuple|1.2.5|6>>
    <associate|auto-11|<tuple|1.2.6|6>>
    <associate|auto-12|<tuple|2|7>>
    <associate|auto-13|<tuple|2.1|7>>
    <associate|auto-14|<tuple|2.1|7>>
    <associate|auto-15|<tuple|2.2|8>>
    <associate|auto-16|<tuple|2.2.1|8>>
    <associate|auto-17|<tuple|2.2.2|8>>
    <associate|auto-18|<tuple|2.2.3|8>>
    <associate|auto-19|<tuple|2.1|8>>
    <associate|auto-2|<tuple|1.1|5>>
    <associate|auto-20|<tuple|2.2.4|9>>
    <associate|auto-21|<tuple|2.2.5|9>>
    <associate|auto-22|<tuple|2.2.6|9>>
    <associate|auto-23|<tuple|3|11>>
    <associate|auto-24|<tuple|3|11>>
    <associate|auto-25|<tuple|2.4.5|9>>
    <associate|auto-26|<tuple|2.4.6|9>>
    <associate|auto-27|<tuple|2.5|9>>
    <associate|auto-28|<tuple|2.5.1|10>>
    <associate|auto-29|<tuple|2.5.2|10>>
    <associate|auto-3|<tuple|1.1.1|5>>
    <associate|auto-30|<tuple|2.5.3|10>>
    <associate|auto-31|<tuple|2.5.4|10>>
    <associate|auto-32|<tuple|2.5.5|10>>
    <associate|auto-33|<tuple|2.5.6|10>>
    <associate|auto-34|<tuple|2.5.7|10>>
    <associate|auto-35|<tuple|2.5.8|10>>
    <associate|auto-36|<tuple|2.5.9|10>>
    <associate|auto-37|<tuple|2.5.10|11>>
    <associate|auto-38|<tuple|2.5.11|?>>
    <associate|auto-39|<tuple|3|?>>
    <associate|auto-4|<tuple|1.1.2|5>>
    <associate|auto-40|<tuple|2.5.11|?>>
    <associate|auto-41|<tuple|3|?>>
    <associate|auto-5|<tuple|1.2|6>>
    <associate|auto-6|<tuple|1.2.1|6>>
    <associate|auto-7|<tuple|1.2.2|6>>
    <associate|auto-8|<tuple|1.2.3|6>>
    <associate|auto-9|<tuple|1.2.4|6>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|figure>
      <tuple|normal|Components|<pageref|auto-14>>
    </associate>
    <\associate|table>
      <tuple|normal|Dependencies|<pageref|auto-19>>
    </associate>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|1<space|2spc>Design>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>

      1.1<space|2spc>Goals <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-2>

      <with|par-left|<quote|1tab>|1.1.1<space|2spc>The TUI
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-3>>

      <with|par-left|<quote|1tab>|1.1.2<space|2spc>The Planner
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-4>>

      1.2<space|2spc>Decisions <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-5>

      <with|par-left|<quote|1tab>|1.2.1<space|2spc>Only Lines Have Directions
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-6>>

      <with|par-left|<quote|1tab>|1.2.2<space|2spc>No Direction Change When
      Searching <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-7>>

      <with|par-left|<quote|1tab>|1.2.3<space|2spc>Stops Are Visited Only
      Once <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-8>>

      <with|par-left|<quote|1tab>|1.2.4<space|2spc>Only Display Least Changes
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-9>>

      <with|par-left|<quote|1tab>|1.2.5<space|2spc>Use
      <with|font-family|<quote|tt>|language|<quote|verbatim>|glibc> for
      <with|font-family|<quote|tt>|language|<quote|verbatim>|UTF-8> Handling
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-10>>

      <with|par-left|<quote|1tab>|1.2.6<space|2spc>Use
      <with|font-family|<quote|tt>|language|<quote|verbatim>|graphviz> for
      Graph Visualization <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-11>>

      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|2<space|2spc>Implementation>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-12><vspace|0.5fn>

      2.1<space|2spc>Overview <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-13>

      2.2<space|2spc>Challenges <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-15>

      <with|par-left|<quote|1tab>|2.2.1<space|2spc>Route Planning
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-16>>

      <with|par-left|<quote|1tab>|2.2.2<space|2spc>Unicode Handling
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-17>>

      <with|par-left|<quote|1tab>|2.2.3<space|2spc>The TUI
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-18>>

      <with|par-left|<quote|1tab>|2.2.4<space|2spc>File Changes Monitoring
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-20>>

      <with|par-left|<quote|1tab>|2.2.5<space|2spc>Signal Handling
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-21>>

      <with|par-left|<quote|1tab>|2.2.6<space|2spc>Presentation of Plans
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-22>>

      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|3<space|2spc>Summary
      and Thoughts> <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-23><vspace|0.5fn>
    </associate>
  </collection>
</auxiliary>