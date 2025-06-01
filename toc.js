// Populate the sidebar
//
// This is a script, and not included directly in the page, to control the total size of the book.
// The TOC contains an entry for each page, so if each page includes a copy of the TOC,
// the total size of the page becomes O(n**2).
class MDBookSidebarScrollbox extends HTMLElement {
    constructor() {
        super();
    }
    connectedCallback() {
        this.innerHTML = '<ol class="chapter"><li class="chapter-item expanded affix "><a href="index.html">Introduction</a></li><li class="chapter-item expanded affix "><li class="part-title">Linux Kernel</li><li class="chapter-item expanded "><a href="kernel/debugging/index.html"><strong aria-hidden="true">1.</strong> Debugging</a></li><li><ol class="section"><li class="chapter-item expanded "><a href="kernel/debugging/Understanding-Linux-Kernel-Oops.html"><strong aria-hidden="true">1.1.</strong> Understanding Kernel Oops</a></li><li class="chapter-item expanded "><a href="kernel/debugging/Tools-and-Techniques-to-Debug-an-Linux-System.html"><strong aria-hidden="true">1.2.</strong> Tools &amp; Techniques to Debug a LinuxSystem</a></li><li class="chapter-item expanded "><a href="kernel/debugging/Dynamic-program-analysis.html"><strong aria-hidden="true">1.3.</strong> Dynamic Program Analysis</a></li><li class="chapter-item expanded "><a href="kernel/debugging/Fuzzing-Linux-Kernel.html"><strong aria-hidden="true">1.4.</strong> Fuzzing Linux Kernel</a></li><li class="chapter-item expanded "><a href="kernel/debugging/How-To-use-syzkaller.html"><strong aria-hidden="true">1.5.</strong> How to use syzkaller</a></li><li class="chapter-item expanded "><a href="kernel/debugging/Reproducing-bugs-from-syzkaller.html"><strong aria-hidden="true">1.6.</strong> Reproducing bugs from syzkaller</a></li><li class="chapter-item expanded "><a href="kernel/debugging/Solving-syzkaller-bugs.html"><strong aria-hidden="true">1.7.</strong> Solving bugs from syzkaller</a></li><li class="chapter-item expanded "><a href="kernel/debugging/Event-Tracing.html"><strong aria-hidden="true">1.8.</strong> Event tracing</a></li><li class="chapter-item expanded "><a href="kernel/debugging/Event-tracing-for-debugging.html"><strong aria-hidden="true">1.9.</strong> Event tracing for Debugging</a></li></ol></li><li class="chapter-item expanded "><a href="kernel/camera-driver/index.html"><strong aria-hidden="true">2.</strong> Camera Driver</a></li><li><ol class="section"><li class="chapter-item expanded "><a href="kernel/camera-driver/03.html"><strong aria-hidden="true">2.1.</strong> Introduction to Gstreamer</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/04.html"><strong aria-hidden="true">2.2.</strong> Color Formats RGB vs YUV</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/05.html"><strong aria-hidden="true">2.3.</strong> Internal Working of the camera Sensor</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/06.html"><strong aria-hidden="true">2.4.</strong> Image Processing Pipeline</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/15.html"><strong aria-hidden="true">2.5.</strong> Introduction to MIPI/CSI ports</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/16.html"><strong aria-hidden="true">2.6.</strong> Study of camera sensors</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/01.html"><strong aria-hidden="true">2.7.</strong> Introduction to Device Drivers</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/09.html"><strong aria-hidden="true">2.8.</strong> Hello World Device Driver</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/10.html"><strong aria-hidden="true">2.9.</strong> Introduction to Char driver</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/02.html"><strong aria-hidden="true">2.10.</strong> Camera driver Architecture</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/11.html"><strong aria-hidden="true">2.11.</strong> Structure of the camera device driver</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/07.html"><strong aria-hidden="true">2.12.</strong> Introduction to Device Trees</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/12.html"><strong aria-hidden="true">2.13.</strong> Write Device Tree for the camera module</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/13.html"><strong aria-hidden="true">2.14.</strong> Camera driver power and startup block</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/14.html"><strong aria-hidden="true">2.15.</strong> Camera driver Initialization</a></li><li class="chapter-item expanded "><a href="kernel/camera-driver/17.html"><strong aria-hidden="true">2.16.</strong> Combining all blocks</a></li></ol></li><li class="chapter-item expanded "><li class="part-title">Programming</li><li class="chapter-item expanded "><a href="programming/rust/index.html"><strong aria-hidden="true">3.</strong> Rust</a></li><li><ol class="section"><li class="chapter-item expanded "><a href="programming/rust/Rust-Data-Types.html"><strong aria-hidden="true">3.1.</strong> Data Types</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Variables-and-Immutability.html"><strong aria-hidden="true">3.2.</strong> Variables &amp; Imutability</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Functions.html"><strong aria-hidden="true">3.3.</strong> Functions</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Closures.html"><strong aria-hidden="true">3.4.</strong> Closures</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Strings.html"><strong aria-hidden="true">3.5.</strong> Strings</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Decision-Making.html"><strong aria-hidden="true">3.6.</strong> Decision Making</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Loops.html"><strong aria-hidden="true">3.7.</strong> Loops</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Struct.html"><strong aria-hidden="true">3.8.</strong> Struct</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Enums.html"><strong aria-hidden="true">3.9.</strong> Enums</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Function-on-Types.html"><strong aria-hidden="true">3.10.</strong> Impl</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Collections.html"><strong aria-hidden="true">3.11.</strong> Collections</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Modules-imports-use-statements.html"><strong aria-hidden="true">3.12.</strong> Modules</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-Slices.html"><strong aria-hidden="true">3.13.</strong> Slices</a></li><li class="chapter-item expanded "><a href="programming/rust/Rust-iterators.html"><strong aria-hidden="true">3.14.</strong> Iterators</a></li></ol></li><li class="chapter-item expanded "><li class="part-title">Libraries</li><li class="chapter-item expanded "><a href="libraries/opencv/index.html"><strong aria-hidden="true">4.</strong> OpenCV</a></li><li><ol class="section"><li class="chapter-item expanded "><a href="libraries/opencv/01.html"><strong aria-hidden="true">4.1.</strong> Understanding Types of Digital Image representation in computers</a></li><li class="chapter-item expanded "><a href="libraries/opencv/02.html"><strong aria-hidden="true">4.2.</strong> CMOS Camera Sensor and its performance parameters</a></li><li class="chapter-item expanded "><a href="libraries/opencv/03.html"><strong aria-hidden="true">4.3.</strong> Basics of Photography</a></li><li class="chapter-item expanded "><a href="libraries/opencv/04.html"><strong aria-hidden="true">4.4.</strong> OpenCV - Basics</a></li><li class="chapter-item expanded "><a href="libraries/opencv/05.html"><strong aria-hidden="true">4.5.</strong> Reading/Writing an Image</a></li><li class="chapter-item expanded "><a href="libraries/opencv/06.html"><strong aria-hidden="true">4.6.</strong> Image Processing - Accessing Pixels, Transform Color Spaces</a></li><li class="chapter-item expanded "><a href="libraries/opencv/15.html"><strong aria-hidden="true">4.7.</strong> Image Processing - Image Transforms</a></li><li class="chapter-item expanded "><a href="libraries/opencv/07.html"><strong aria-hidden="true">4.8.</strong> Image Processing - Scaling and Cropping</a></li><li class="chapter-item expanded "><a href="libraries/opencv/08.html"><strong aria-hidden="true">4.9.</strong> Image Processing - Filtering Images</a></li><li class="chapter-item expanded "><a href="libraries/opencv/09.html"><strong aria-hidden="true">4.10.</strong> Image Processing - Histograms</a></li><li class="chapter-item expanded "><a href="libraries/opencv/10.html"><strong aria-hidden="true">4.11.</strong> Contour detection</a></li><li class="chapter-item expanded "><a href="libraries/opencv/11.html"><strong aria-hidden="true">4.12.</strong> Thresholding</a></li><li class="chapter-item expanded "><a href="libraries/opencv/12.html"><strong aria-hidden="true">4.13.</strong> Features detection, extraction and matching</a></li><li class="chapter-item expanded "><a href="libraries/opencv/13.html"><strong aria-hidden="true">4.14.</strong> Object Detection</a></li><li class="chapter-item expanded "><a href="libraries/opencv/14.html"><strong aria-hidden="true">4.15.</strong> Motion and Tracking</a></li><li class="chapter-item expanded "><a href="libraries/opencv/16.html"><strong aria-hidden="true">4.16.</strong> Detecting Depth</a></li></ol></li></ol>';
        // Set the current, active page, and reveal it if it's hidden
        let current_page = document.location.href.toString().split("#")[0].split("?")[0];
        if (current_page.endsWith("/")) {
            current_page += "index.html";
        }
        var links = Array.prototype.slice.call(this.querySelectorAll("a"));
        var l = links.length;
        for (var i = 0; i < l; ++i) {
            var link = links[i];
            var href = link.getAttribute("href");
            if (href && !href.startsWith("#") && !/^(?:[a-z+]+:)?\/\//.test(href)) {
                link.href = path_to_root + href;
            }
            // The "index" page is supposed to alias the first chapter in the book.
            if (link.href === current_page || (i === 0 && path_to_root === "" && current_page.endsWith("/index.html"))) {
                link.classList.add("active");
                var parent = link.parentElement;
                if (parent && parent.classList.contains("chapter-item")) {
                    parent.classList.add("expanded");
                }
                while (parent) {
                    if (parent.tagName === "LI" && parent.previousElementSibling) {
                        if (parent.previousElementSibling.classList.contains("chapter-item")) {
                            parent.previousElementSibling.classList.add("expanded");
                        }
                    }
                    parent = parent.parentElement;
                }
            }
        }
        // Track and set sidebar scroll position
        this.addEventListener('click', function(e) {
            if (e.target.tagName === 'A') {
                sessionStorage.setItem('sidebar-scroll', this.scrollTop);
            }
        }, { passive: true });
        var sidebarScrollTop = sessionStorage.getItem('sidebar-scroll');
        sessionStorage.removeItem('sidebar-scroll');
        if (sidebarScrollTop) {
            // preserve sidebar scroll position when navigating via links within sidebar
            this.scrollTop = sidebarScrollTop;
        } else {
            // scroll sidebar to current active section when navigating via "next/previous chapter" buttons
            var activeSection = document.querySelector('#sidebar .active');
            if (activeSection) {
                activeSection.scrollIntoView({ block: 'center' });
            }
        }
        // Toggle buttons
        var sidebarAnchorToggles = document.querySelectorAll('#sidebar a.toggle');
        function toggleSection(ev) {
            ev.currentTarget.parentElement.classList.toggle('expanded');
        }
        Array.from(sidebarAnchorToggles).forEach(function (el) {
            el.addEventListener('click', toggleSection);
        });
    }
}
window.customElements.define("mdbook-sidebar-scrollbox", MDBookSidebarScrollbox);
