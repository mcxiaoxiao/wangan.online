---
title: HIT837三科答题手册
description: 哈尔滨工业大学网络与信息安全、网络空间安全在线考研知识库 🎓 哈工大网安837自命题考研三科答题手册 🎓 HIT837-Book-of-answer（wangan.online） 🎓 仓库提供背题手册、课程PPT、相关题目、交流空间，其中手册部分集概念、个人见解、代码于一体，旨在帮所有网安自命题考生减少重复劳动，高效掌握哈工大计算学部网络空间安全、电子信息类网络与信息安全方向837考研自命题全部核心内容和所需应试技能
---
<div align=center>
<style>
button {
  /* Variables */
  --button_radius: 0.75em;
  --button_color: #f8f8f8ff;
  --button_outline_color: #000000ff;
  font-size: 17px;
  font-weight: bold;
  border: none;
  cursor: pointer;
  border-radius: var(--button_radius);
  background: var(--button_outline_color);
 }
.button_top {
display: block;
box-sizing: border-box;
border: 2px solid var(--button_outline_color);
border-radius: var(--button_radius);
padding: 0.75em 1.5em;
background: var(--button_color);
color: var(--button_outline_color);
transform: translateY(-0.2em);
transition: transform 0.1s ease;
}
button:hover .button_top {
transform: translateY(-0.33em);
}
button:active .button_top {
transform: translateY(0);
}
</style>
<h1><b> HIT837三科答题手册 · 网安在线考研知识库</b></h1>
<img width="100%" alt="image" src="hit837.png" />
</div>

## 资源索引

在线知识库

<div class="grid" markdown>

[:material-math-integral: 信息安全导论知识库](/HIT837-Book-of-Answer/信安基础/0/ "很全")
{ .card }

[:material-shield-outline: 网络安全基础知识库](/HIT837-Book-of-Answer/网安基础/0/ "很全")
{ .card }

[:material-web: 计算机网络知识库](/HIT837-Book-of-Answer/计算机网络/0/ "不全")
{ .card }

[:material-book-open-page-variant-outline: 历年真题和考点统计](/HIT837-Book-of-Answer/%E7%9C%9F%E9%A2%98/ "真题索引和下载")
{ .card }

</div>

仓库资源

<div class="grid" markdown>

[:octicons-discussion-closed-16: 开放论坛](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/discussions "跳转到 GitHub discussion")
{ .card }

[:material-script-text-outline: 精选习题](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/tree/main/%E4%B9%A0%E9%A2%98 "收集到的高质量题目")
{ .card }

[:material-school-outline: 招生信息](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/tree/main/%E6%8B%9B%E7%94%9F%E4%BF%A1%E6%81%AF "复试名单 复试成绩单 录取名单")
{ .card }

[:material-brain: 思维导图](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/tree/main/%E6%80%9D%E7%BB%B4%E5%AF%BC%E5%9B%BE "三科思维导图")
{ .card }

[:octicons-file-code-16: 算法PPT和Python示例](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/tree/page/%E7%AE%97%E6%B3%95 "重要课程 PPT")
{ .card }

[:simple-github: guoJohnny 资料库](https://github.com/guoJohnny/-837- "跳转到 GitHub repo")
{ .card }
</div>


## 手册介绍

作为一个非本校的837跨考选手，我深知备考这样一个小众自命题的不易，我的备考历程完全是有赖于往届同学（感谢zyx学长）的帮助以及guoJohnny前辈的资料库[^1]才会如此顺利。我希望我也能一样以分享的形式给更多同学特别是跨考的同学一些帮助，这不仅是我学生时代自愿整理的第一个笔记本也是我的一种尝试：仓库提供背题手册、课程PPT、相关题目、交流空间，其中手册部分集概念、个人见解、代码于一体，旨在帮所有网安自命题考生减少重复劳动，高效掌握哈工大网安837考研自命题全部核心内容和所需应试技能[^2]。

本仓库的目标是创建一个为实现以下目标的统一资源：

- 在线知识库及仓库所有内容免费开源，由社区共同守护与更新，联合起来消灭837备考信息差，让考研机构无机可乘；
- 提供恰到好处的知识深度，从而帮助读者，快速掌握各部分备考要点，有效应对考试挑战；
- 包含可运行的代码，精选题目与知识点，覆盖信安、网安（共占90分）全部核心考察范围；
- 通过社区力量快速迭代内容，从而紧跟仍不断变化发展的网安自命题考试；
- 由包含有关应试备考细节问答的开放论坛作为补充，使大家可以相互答疑并交换经验。



受限于我的应试和专业能力，本手册作为一本纯粹的应试工具，内容大概经不住严格的审视，但它的主要目的是节省时间，让大家去探索、创造、追求真正的自由和美好。考研不止是值得仔细品味的过程，也是此后自由之旅的一个新起点[^3]。

愿哈工大能有幸录取如此优秀的你！


<!-- <button id="randomButton"> <span class="button_top"> :material-book-open-variant: 随机翻一页 </span></button> -->










## 离线版下载

离线word文档包括在线知识库中所有有关837的内容，覆盖网安信安全部章节(1)；0基础/非科班友好，120+辅助理解的标注(2)和表格(3)；内容详略得当，约6万字，重点特别标记(4)。可以存在自己的设备里或打印出来，方便直接标注笔记和考前翻看。
{ .annotate }

1.  ![Image title](hit837.png){ loading=lazy }
2.  ![Image title](hit837.png){ loading=lazy }
3.  ![Image title](hit837.png){ loading=lazy }
4.  ![Image title](hit837.png){ loading=lazy }


此处提供三种获取方式[^4]：**付费（132￥） / 参与修订（免费） / 以物易物（免费）** 

<div class="grid cards" markdown>

-   :material-cash-check:{ .lg .middle } __付费__

    ---

    扫描收款二维码支付 CNY 132 元，复制微信支付编号。
    
    [:material-qrcode-scan: 微信扫码支付](# "点击后会打开二维码图片，扫码付款后微信搜索微信支付可以找到订单信息")
    
    发送邮件到orlosziming@163.com 标题为：`付费999999999999`（微信支付编号，没有空格）1分钟内自动核验并发送文件，留意收件箱。

    [:octicons-arrow-right-24: 发送邮件](#)

-   :material-file-document-edit:{ .lg .middle } __参与修订__

    ---

    在 :octicons-git-branch-16:page分支 提交PR，帮助优化或扩充这个公益且开源的在线知识库的内容。
    
    [:octicons-arrow-right-24: 提交 Pull Request](#)

    发送邮件到orlosziming@163.com 标题为：`参与修订#123`（您的PR编号）核验后发送文件。

    [:octicons-arrow-right-24: 发送邮件](#)


-   :material-file-document-plus:{ .lg .middle } __以物易物__

    ---
    在 :octicons-git-branch-16:main分支 提交PR，上传您认为质量不错的备考资料。

    [:octicons-arrow-right-24: 提交 Pull Request](#)

    发送邮件到orlosziming@163.com 标题为：`以物易物#123`（您的PR编号）核验后发送文件。

    [:octicons-arrow-right-24: 发送邮件](#)



</div>

## 编辑和支持  <img width="75" height="25" alt="Written-By-Human-Not-By-AI-Badge-black" src="Written-By-Human-Not-By-AI-Badge-black.png" />

在408一统计算机考研的当下维护一个网安自命题主题的小众考研知识库还需诸君支持 ~ 如果您喜欢本项目或愿意拯救世界的话，欢迎 [提交 Pull Request](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/discussions/2) 或 [成为collaborator](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/discussions/2)。您的PR可以 创建/删除/修改 仓库内的任何 文件/文件夹/代码。网站可以提交哈工大837考纲外内容（比如别的学校的），但是请以和现有手册相同的文档结构组织页面。


## 贡献者列表


<a href="https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=mcxiaoxiao/HIT837-Book-of-Answer" />
</a>

感谢以上同学的卓越贡献 :fontawesome-regular-hand-back-fist:


</br>




<script>

  const links = [
    "https://www.google.com",
    "https://www.yahoo.com",
    "https://www.bing.com",
    "https://www.duckduckduckgo.com"
  ];


  const button0 = document.getElementById("randomButton");

  button0.addEventListener("click", function() {

    const randomIndex = Math.floor(Math.random() * links.length);

    const randomLink = links[randomIndex];

    window.open(randomLink, '_blank');
  });
  
</script>

[^1]: 感谢guoJohnny学长惠泽无数后辈的对HIT网络空间安全考研专业课资料的整理与分享: [guoJohnny/-837-](https://github.com/guoJohnny/-837- "哈尔滨工业大学考研 网络与空间安全 837 初试资料库") 
[^3]: 
  多年来我相信且践行，通过自学和自主寻找资源，也可以不错的地理解学科知识，也许还能更有批判性思维和解决问题的能力。循此以论，学习的本真在于独立与自由。我在毕业之际整理本手册的目的之一也是希望更多人能和我一起相信这一假设：蔑视绩优导向，主动拒绝学科补课，同样可以实现一些目标。希望我们能改善学风，让求知回归纯粹，让教育回归人本。大家可以通过发声或切实的行动，让缺少话语权的，您和您的家人可能正在经历或经历过的占据每个人一生中几乎1/4的时间的幼儿园小中大学阶段，也能有更多获得感、幸福感。相关资源：[教育部办公厅关于印发《查处中小学违规办学行为典型案例》的通知_教育部](http://www.moe.gov.cn/srcsite/A06/s7053/202504/t20250407_1186364.html)；[各地中小学规范办学行为举报平台_中国教育在线](https://www.eol.cn/news/yaowen/202504/t20250411_2663298.shtml)； [人民群众留言入口_中国政府网](https://liuyan.www.gov.cn/hudong/atwls/rmqz.htm)； [向部委、地方、地方人大、地方政协提建议_人民网](https://liuyan.people.com.cn/rmjy)；[发起相关请愿_change.org](https://www.change.org/)，[教育部巡视工作办公室巡视信息公开_教育部](https://hudong.moe.gov.cn/s78/A28/s7819/s8173/2025xsxxgk02/)
[^2]: 
  我反对升学和竞争导向，更反对一切以应试为目的的补习文化。从K12阶段直至大学，我们的公立教育体系不应该是一种贯彻始终的竞争导向的体系，而应是一个更强调发现自我、发展潜能的体系。应该提倡大家根据自己的兴趣和节奏来学习，而非要求所有人适应一个预制的、标准化的、单一的评价标准。公立教育系统应该提供一个支持性和包容性的环境，让学生在其中自由地探索、实验和学习。教育不是竞争，禁止以分数排名学生，强制执行双休，清理各种多余的学科类补习班的行动应在全国所有地区坚定有力地被落实，从制度层面确保类似衡水模式的时代悲剧不会再次发生，大家也应自觉反对任何有意强调分数和排名的行为。一个人民立场国家的教育的本质应当是帮助人建立自信，发扬人的个性，以及准备成为思想自由的终身学习者。人民满意是发展教育的根本尺度，从一个9年义务教育以及公立普通高中普通本科的体验者的视角来看，我深信以上这些是办好大部分学生或许也是人民满意的教育的必由之路。
[^4]:
  打破信息差，知识应为人人。 我们的网站内容始终免费开源，践行此志。离线手册保留版权，确保项目的可持续发展。837每年报考人数太少可能导致仓库断更，开源仓库信息收集不全反而会成全那些高价贩卖信息差的考研机构，这完全违背仓库的本意。我的手册docx文档就当抛砖引玉，希望同学们在受益的同时能考虑帮助这个仓库活下去（例如上传回忆版真题、勘误、共享笔记资料）。另外，网站永久开源不可能收费，**离线文档在内容上与网站无异**，离线文档主要是方便编辑和打印，且离线版用软件自带Ctrl+F搜索关键词大概没有网站的模糊搜索能力。

  