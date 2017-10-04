import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import http from 'axios';
import '../node_modules/github-fork-ribbon-css/gh-fork-ribbon.css';

class App extends Component {
    constructor() {
        super();
        this.state = {
            username: 'bareinhard',
            repo: 'hacktoberfest-data-structure-and-algorithms',
            rootContent: [],
            rootDirectories: [],
            currentDirectory: [],
            displayCode: false,
            code: '',
            rootTree: [],
            codeContent: {},
        };
        this.loadFiles();
    }
    sanitizeWord = val => {
        val = this.removeUnderscore(val);
        return val;
    };
    removeUnderscore = val => {
        val = val.replace(/_/g, ' ');
        val = this.properName(val);
        return val;
    };
    properName = val => {
        val = val.split(' ');
        val = val.map(word => word.substring(0, 1).toUpperCase() + word.substring(1));
        val = val.join(' ');
        return val;
    };
    getRootFiles = async () => {
        let rootContent = await http
            .get(`https://api.github.com/repos/${this.state.username}/${this.state.repo}/contents/`)
            .then(res => res.data);
        let rootTree = [];
        let codeContent = {};
        for (let dir of rootContent) {
            if (dir.size === 0) {
                let treeObject = await http
                    .get(
                        `https://api.github.com/repos/${this.state.username}/${this.state
                            .repo}/git/trees/${dir.sha}?recursive=1`,
                    )
                    .then(res => res.data);
                treeObject.name = dir.name;
                treeObject.path = dir.path;
                treeObject.tree.forEach(files => {
                    codeContent[files.path] = '...';
                }),
                    rootTree.push(treeObject);
            }
        }

        let rootDirectories = rootContent.filter(file => file.size === 0);
        console.log(rootTree);

        this.setState({ rootContent, rootDirectories, rootTree, codeContent });
    };
    loadFiles = async () => {
        this.getRootFiles('bareinhard', 'hacktoberfest-data-structure-and-algorithms');
    };
    clickDirectory = event => {
        let path = event.target.className;
        http
            .get(`https://api.github.com/repos/${this.state.username}/${this.state.repo}/contents/${path}?ref=master`)
            .then(res => {
                let newRoot = res.data;
                console.log(newRoot);
                let codeContent = {};
                newRoot.forEach(rootDir =>
                    rootDir.tree.forEach(files => {
                        codeContent[files.path] = '...';
                    }),
                );
                this.setState({ codeContent, currentDirectory: Array(...newRoot) });
            });
    };
    displayCode = async event => {
        let path = event.target.className;
        let res = await http.get(`${path}`).then(res => res.data);
        console.log(res);
        this.setState({
            code: atob(res.content),
            displayCode: true,
        });
    };
    filerSubDirectories = event => {
        let path = event.target.id;
        let currentDirectory = this.state.rootTree.filter(dir => dir.sha === path);
        console.log(currentDirectory);
        currentDirectory = currentDirectory[0].tree.filter(dir => !dir.path.includes('/'));
        this.setState({ currentDirectory });
    };
    loadCode = async event => {
        let path = event.target.id;
        let code = await http
            .get(`https://api.github.com/repos/${this.state.username}/${this.state.repo}/contents/${path}?ref=master`)
            .then(res => res.data);
        let newPath = path.split('/');
        let finalPath = '';
        for (let sub of newPath) {
            if (sub === newPath[1] && sub !== newPath[0]) {
                finalPath += sub;
            } else if (sub !== newPath[0]) {
                finalPath += '/' + sub;
            }
        }
        console.log(finalPath, this.state.codeContent);
        this.setState({
            codeContent: Object.assign({}, this.state.codeContent, { [finalPath]: atob(code.content) }),
        });
    };
    render() {
        return (
            <div className="App">
                <header className="App-header">
                    <a
                        className="github-fork-ribbon"
                        href={`https://github.com/${this.state.username}/${this.state.repo}`}
                        data-ribbon="Fork me on GitHub"
                        title="Fork me on GitHub"
                    >
                        Fork me on GitHub
                    </a>
                    <img src={logo} className="App-logo" alt="logo" />
                </header>
                {this.state.rootTree.map(directory => (
                    <div
                        onClick={this.filerSubDirectories}
                        id={directory.sha}
                        className="directory-button"
                        key={directory.sha}
                    >
                        {this.sanitizeWord(directory.name)}
                    </div>
                ))}
                <div className="directory-choice-container">
                    {this.state.currentDirectory.map(
                        dir =>
                            !dir.path.includes('/') ? (
                                <a className="directory-choice" key={dir.sha} href={`#${dir.path}`}>
                                    <div>{this.sanitizeWord(dir.path)}</div>
                                </a>
                            ) : (
                                ''
                            ),
                    )}
                </div>
                <div className="content-container">
                    {this.state.rootTree.map(dir => (
                        <div key={dir.path} className="content">
                            <h3 className="content-header">{this.sanitizeWord(dir.name)}</h3>
                            {dir.tree.map(subdir => {
                                let subs = [];

                                return !subdir.path.includes('/') ? (
                                    <div key={`${dir.path}/toplevel${subdir.path}`} className="sub-content">
                                        <h4 className="subcontent-header" id={subdir.path}>
                                            {this.sanitizeWord(subdir.path)}
                                        </h4>
                                        {dir.tree.map(subsubdir => {
                                            let subName = subsubdir.path.split('/');

                                            if (
                                                subsubdir.path.includes('/') &&
                                                subName[0] === subdir.path &&
                                                !subs.includes(subName[1])
                                            ) {
                                                console.log(subName, !subs.includes(subName), subs);
                                                subs.push(subName[1]);
                                                return (
                                                    <div
                                                        className="language-sub-content"
                                                        key={`${dir.path}/${subName[1]}`}
                                                    >
                                                        <h5 className="language-subcontent-header">
                                                            Language:{' '}
                                                            <span className="language">
                                                                {this.sanitizeWord(subsubdir.path.split('/')[1])}
                                                            </span>
                                                        </h5>
                                                        {dir.tree.map(
                                                            files =>
                                                                files.path.includes(subName[0] + '/' + subName[1]) &&
                                                                files.path.includes('.') ? (
                                                                    <div key={`${dir.path}/${files.path}`}>
                                                                        <h4 className="file-name-header">
                                                                            File Name:{' '}
                                                                            <span className="file-name">
                                                                                {
                                                                                    files.path.split('/')[
                                                                                        files.path.split('/').length - 1
                                                                                    ]
                                                                                }
                                                                            </span>
                                                                        </h4>
                                                                        <button
                                                                            className="view-code-button"
                                                                            id={`${dir.path}/${files.path}`}
                                                                            onClick={this.loadCode}
                                                                        >
                                                                            View Code
                                                                        </button>
                                                                        <div
                                                                            style={{
                                                                                position: 'relative',
                                                                                whiteSpace: 'nowrap',
                                                                                textAlign: 'left',
                                                                            }}
                                                                        >
                                                                            <pre>
                                                                                {this.state.codeContent[files.path]}
                                                                            </pre>
                                                                        </div>
                                                                    </div>
                                                                ) : (
                                                                    ''
                                                                ),
                                                        )}
                                                    </div>
                                                );
                                            } else {
                                                return '';
                                            }
                                        })}
                                    </div>
                                ) : (
                                    ''
                                );
                            })}
                        </div>
                    ))}
                </div>

                {/* Display Code*/}
            </div>
        );
    }
}

export default App;
