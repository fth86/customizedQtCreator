#include <vcsbase/vcsbaseconstants.h>
    const auto widgetCreator = []() { return new GitEditorWidget; };
        addAutoReleasedObject(new VcsEditorFactory(editorParameters + i, widgetCreator, m_gitClient, describeSlot));

    auto cloneWizardFactory = new VcsBase::BaseCheckoutWizardFactory;
    cloneWizardFactory->setId(QLatin1String(VcsBase::Constants::VCS_ID_GIT));
    cloneWizardFactory->setIcon(QIcon(QLatin1String(":/git/images/git.png")));
    cloneWizardFactory->setDescription(tr("Clones a Git repository and tries to load the contained project."));
    cloneWizardFactory->setDisplayName(tr("Git Repository Clone"));
    cloneWizardFactory->setWizardCreator([this] (const Utils::FileName &path, QWidget *parent) {
        return new CloneWizard(path, parent);
    });
    addAutoReleasedObject(cloneWizardFactory);

    // A wizard allowing for browsing Gitorious-hosted projects.
    cloneWizardFactory = new VcsBase::BaseCheckoutWizardFactory;
    cloneWizardFactory->setId(QLatin1String(VcsBase::Constants::VCS_ID_GIT));
    cloneWizardFactory->setIcon(QIcon(QLatin1String(":/git/images/gitorious.png")));
    cloneWizardFactory->setDescription(tr("Clones a Gitorious repository and tries to load the contained project."));
    cloneWizardFactory->setDisplayName(tr("Gitorious Repository Clone"));
    cloneWizardFactory->setWizardCreator([this] (const Utils::FileName &path, QWidget *parent) {
        return new Gitorious::Internal::GitoriousCloneWizard(path, parent);
    });
    addAutoReleasedObject(cloneWizardFactory);
                           globalcontext, true, SLOT(startCommit()),
                           QKeySequence(UseMacShortcuts ? tr("Meta+G,Meta+C") : tr("Alt+G,Alt+C")));
    QTC_ASSERT(submitEditor(), return);
    EditorManager::closeDocument(submitEditor()->document());
    GitEditorWidget editor;
    editor.setParameters(editorParameters + 3);
    GitEditorWidget editor;
    editor.setParameters(editorParameters + 1);