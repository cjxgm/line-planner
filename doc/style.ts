<TeXmacs|1.0.7.21>

<style|source>

<\body>
  <assign|term|<\macro|short|full>
    <\with|color|#c05520>
      <arg|short><rsup| <arg|full>>
    </with>
  </macro>>

  <assign|abbr-def|<\macro|full|abbr>
    <\with|color|#c05520|the-label|<arg|abbr>>
      <label|<arg|abbr>><arg|full><rsup| (<arg|abbr>)>
    </with>
  </macro>>

  <assign|abbr|<macro|abbr|<reference|<arg|abbr>>>>

  <assign|fixme|<macro|content|msg|<space|2spc><with|color|red|<underline|<with|font|roman|font-family|tt|FIXME><space|4spc><with|color||<arg|content>>>><with|color|dark
  red|<rsup|<arg|msg>>>>>

  <assign|important|<macro|content|<yes-indent><with|color|#c05520|<block|<tformat|<table|<row|<cell|<tabular|<tformat|<twith|table-lsep|0.5fn>|<twith|table-rsep|0.5fn>|<twith|table-bsep|0.2fn>|<twith|table-tsep|0.2fn>|<table|<row|<cell|<arg|content>>>>>>>>>>>><no-indent*>>>

  <assign|emp|<macro|body|<with|color|#995522|font|concrete|<arg|body>>>>

  \;

  paragraph format

  <assign|par-flexibility|20>

  <assign|par-sep|0.1fn>

  <assign|par-par-sep|0.6fn>

  \;

  document format

  <assign|bg-color|#fff6ed>

  \;

  sectional format

  <assign|chapter-numbered-title|<macro|title|<style-with|src-compact|none|<chapter-title|<with|color|#c05520|Chapter
  <the-chapter>><vspace|1fn><new-line><space|0.6fn><with|color|#995522|<arg|title>>>>>>

  <assign|section-title|<macro|name|<style-with|src-compact|none|<sectional-normal-bold|<vspace*|3fn><very-large|<with|color|#c05520|<arg|name>>><vspace|1fn>>>>>

  \;
</body>

<\initial>
  <\collection>
    <associate|page-medium|automatic>
  </collection>
</initial>

<\references>
  <\collection>
    <associate||<tuple|\<#FF08\>\<#FF09\>|?>>
    <associate|test|<tuple|test|?>>
    <associate|x|<tuple|?|?>>
  </collection>
</references>