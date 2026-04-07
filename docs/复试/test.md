---
title: 外部md文件测试
---

<div id="external-md-content">加载中...</div>

<script src="https://cdn.jsdelivr.net/npm/marked/marked.min.js"></script>
<script>
fetch("https://raw.githubusercontent.com/mcxiaoxiao/wangan.online/refs/heads/HIT-CS-Reexam/%E6%95%B0%E6%8D%AE%E5%BA%93/5.%E6%95%B0%E6%8D%AE%E5%BB%BA%E6%A8%A1ER%26IDEF1x.md?token=GHSAT0AAAAAADLPNOV3RWZISPULMEJQKCRC2OTR2BQ")
  .then(response => response.text())
  .then(markdown => {
    // 替换图片路径
    markdown = markdown.replace(/src="\.\/image\//g, 'src="https://raw.githubusercontent.com/mcxiaoxiao/wangan.online/HIT-CS-Reexam/数据库/image/');
    document.getElementById("external-md-content").innerHTML = marked.parse(markdown);
  })
  .catch(err => {
    document.getElementById("external-md-content").innerText = "加载失败，请检查网络或链接";
  });
</script>