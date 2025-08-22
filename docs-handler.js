// JavaScript for handling pre-uploaded documents from the docs folder
const preUploadedDocs = [
    {
        name: "网络安全基础概念.md",
        path: "docs/samples/网络安全基础概念.md",
        type: "markdown",
        subject: "网络安全",
        description: "网络安全的基本概念、目标和威胁"
    }
    // Add more pre-uploaded documents here
];

function loadPreUploadedDocs() {
    const preDocsList = document.getElementById('preUploadedDocs');
    
    if (preUploadedDocs.length === 0) {
        preDocsList.innerHTML = '<li style="text-align: center; color: #6c757d; padding: 20px;">暂无预置文档</li>';
        return;
    }

    preDocsList.innerHTML = preUploadedDocs.map((doc, index) => `
        <li class="document-item">
            <div class="document-info">
                <div class="document-name">${doc.name}</div>
                <div class="document-meta">
                    科目: ${doc.subject} | 
                    类型: ${doc.type.toUpperCase()} |
                    描述: ${doc.description}
                </div>
            </div>
            <button class="view-btn" onclick="viewPreUploadedDoc(${index})">查看</button>
        </li>
    `).join('');
}

async function viewPreUploadedDoc(index) {
    const doc = preUploadedDocs[index];
    const viewerSection = document.getElementById('viewerSection');
    const currentDocName = document.getElementById('currentDocName');
    const documentContent = document.getElementById('documentContent');

    currentDocName.textContent = doc.name;
    documentContent.innerHTML = '<div class="loading">正在加载文档...</div>';
    viewerSection.style.display = 'block';

    // 滚动到查看器
    viewerSection.scrollIntoView({ behavior: 'smooth' });

    try {
        const response = await fetch(doc.path);
        if (!response.ok) {
            throw new Error(`HTTP ${response.status}: ${response.statusText}`);
        }
        
        const content = await response.text();
        
        if (doc.type === 'markdown') {
            // 简单的 Markdown 转 HTML（基础功能）
            documentContent.innerHTML = convertMarkdownToHtml(content);
        } else {
            documentContent.innerHTML = `<pre>${content}</pre>`;
        }
    } catch (error) {
        console.error('文档加载错误:', error);
        documentContent.innerHTML = `
            <div class="error">
                <strong>文档加载失败</strong><br>
                错误信息: ${error.message}<br>
                请检查文档路径是否正确。
            </div>
        `;
    }
}

function convertMarkdownToHtml(markdown) {
    // 简单的 Markdown 转换器（基础功能）
    let html = markdown
        // 标题
        .replace(/^### (.*$)/gm, '<h3>$1</h3>')
        .replace(/^## (.*$)/gm, '<h2>$1</h2>')
        .replace(/^# (.*$)/gm, '<h1>$1</h1>')
        // 粗体
        .replace(/\*\*(.*?)\*\*/g, '<strong>$1</strong>')
        // 斜体
        .replace(/\*(.*?)\*/g, '<em>$1</em>')
        // 代码块
        .replace(/```([\s\S]*?)```/g, '<pre><code>$1</code></pre>')
        // 行内代码
        .replace(/`(.*?)`/g, '<code>$1</code>')
        // 链接
        .replace(/\[([^\]]+)\]\(([^)]+)\)/g, '<a href="$2">$1</a>')
        // 列表项
        .replace(/^- (.*$)/gm, '<li>$1</li>')
        // 换行
        .replace(/\n/g, '<br>');

    // 包装列表项
    html = html.replace(/(<li>.*<\/li>)/g, '<ul>$1</ul>');
    
    return html;
}