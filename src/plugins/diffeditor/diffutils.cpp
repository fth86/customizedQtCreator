** conditions see http://www.qt.io/licensing.  For further information
** use the contact form at http://www.qt.io/contact-us.
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
    int pos = chunkRegExp.indexIn(patch);
            const int leftStartingPos = chunkRegExp.cap(1).toInt();
            const int rightStartingPos = chunkRegExp.cap(2).toInt();
            const QString contextInfo = chunkRegExp.cap(3);
            pos += chunkRegExp.matchedLength();
        } while ((pos = chunkRegExp.indexIn(patch, pos, QRegExp::CaretAtOffset)) != -1);
    if (leftFileRegExp.indexIn(patch) == 0) {
        patch.remove(0, leftFileRegExp.matchedLength());
        fileData.leftFileInfo.fileName = leftFileRegExp.cap(1);
        if (rightFileRegExp.indexIn(patch) == 0) {
            patch.remove(0, rightFileRegExp.matchedLength());
            fileData.rightFileInfo.fileName = rightFileRegExp.cap(1);
    } else if (binaryRegExp.indexIn(patch) == 0) {
        fileData.leftFileInfo.fileName = binaryRegExp.cap(1);
        fileData.rightFileInfo.fileName = binaryRegExp.cap(2);
    int pos = diffRegExp.indexIn(patch);
            pos += diffRegExp.matchedLength();
    const QRegExp indexRegExp(QLatin1String("^index (\\w+)\\.{2}(\\w+)(?: \\d+)?(\\n|$)")); // index cap1..cap2(optionally: octal)
    if (newFileMode.indexIn(patch) == 0) {
        patch.remove(0, newFileMode.matchedLength());
    } else if (deletedFileMode.indexIn(patch) == 0) {
        patch.remove(0, deletedFileMode.matchedLength());
    if (indexRegExp.indexIn(patch) == 0) {
        fileData.leftFileInfo.typeInfo = indexRegExp.cap(1);
        fileData.rightFileInfo.typeInfo = indexRegExp.cap(2);
        patch.remove(0, indexRegExp.matchedLength());
        } else if (leftFileRegExp.indexIn(patch) == 0) {
            patch.remove(0, leftFileRegExp.matchedLength());
            if (rightFileRegExp.indexIn(patch) == 0) {
                patch.remove(0, rightFileRegExp.matchedLength());
        } else if (binaryRegExp.indexIn(patch) == 0) {
    const QRegExp indexRegExp(QLatin1String("^index (\\w+)\\.{2}(\\w+)(?: \\d+)?(\\n|$)")); // index cap1..cap2(optionally: octal)
        if (indexRegExp.indexIn(patch) == 0) {
            fileData.leftFileInfo.typeInfo = indexRegExp.cap(1);
            fileData.rightFileInfo.typeInfo = indexRegExp.cap(2);
            patch.remove(0, indexRegExp.matchedLength());
            if (leftFileRegExp.indexIn(patch) == 0) {
                patch.remove(0, leftFileRegExp.matchedLength());
                if (rightFileRegExp.indexIn(patch) == 0) {
                    patch.remove(0, rightFileRegExp.matchedLength());
    const QRegExp simpleGitRegExp(QLatin1String("(?:\\n|^)diff --git a/([^\\n]+) b/\\1\\n")); // diff --git a/cap1 b/cap1
                  "(?:\\n|^)diff --git a/([^\\n]+) b/([^\\n]+)\\n" // diff --git a/cap1 b/cap2
                  "(copy|rename) from \\1\\n"                      // copy / rename from cap1
                  "\\3 to \\2\\n"));                               // copy / rename (cap3) to cap2
    bool simpleGitMatched;
    int pos = 0;
    auto calculateGitMatchAndPosition = [&]() {
        const int simpleGitPos = simpleGitRegExp.indexIn(patch, pos, QRegExp::CaretAtOffset);
        const int similarityPos = similarityRegExp.indexIn(patch, pos, QRegExp::CaretAtOffset);
        if (simpleGitPos < 0) {
            pos = similarityPos;
            simpleGitMatched = false;
            return;
        } else if (similarityPos < 0) {
            pos = simpleGitPos;
            simpleGitMatched = true;
            return;
        }
    };

    // Set both pos and simpleGitMatched according to the first match:
    calculateGitMatchAndPosition();
                const QString fileName = simpleGitRegExp.cap(1);
                pos += simpleGitRegExp.matchedLength();
                lastLeftFileName = similarityRegExp.cap(1);
                lastRightFileName = similarityRegExp.cap(2);
                const QString operation = similarityRegExp.cap(3);
                pos += similarityRegExp.matchedLength();
            // give both pos and simpleGitMatched a new value for the next match
            calculateGitMatchAndPosition();
    const int pos = formatPatchEndingRegExp.indexIn(patch);